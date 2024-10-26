 #include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <ctime>

#include "Headers/Global.hpp"
#include "Headers/GetColor.hpp"
#include "Headers/Tetromino.hpp"
#include "Headers/Clear.hpp"

int main()
{
    std::srand(std::time(nullptr));

    sf::Font font;
    font.setSmooth(false);
    font.loadFromFile("font.otf");

    unsigned int score = 0;
    sf::Text score_text(std::to_string(score), font, 9);
    score_text.setPosition(84, 147);

    sf::Event event;

    sf::Clock fps_clock;
    int fps_count = 0;

    std::vector<std::vector<unsigned char>> matrix(COLUMNS, std::vector<unsigned char>(ROWS, CC_GREY));

    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_RESIZE + 48 * SCREEN_RESIZE,
                                          CELL_SIZE * ROWS * SCREEN_RESIZE), sf::String("FPS: 0"));
    window.setFramerateLimit(60);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS + 48, CELL_SIZE * ROWS)));

    Tetromino tetromino(0);
    tetromino.update_shadow(matrix);
    sf::Clock fall_clock;

    bool move_check = true;
    sf::Clock move_clock;

    bool rotate_check = true;
    bool move_faster_check = true;
    bool fall_check = true;

    while (window.isOpen())
    {
        if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
        {
            window.setTitle("FPS: " + std::to_string(fps_count));
            fps_count = 0;
            fps_clock.restart();
        }


        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                case sf::Event::KeyReleased:
                {
                    switch (event.key.code)
                    {
                        case sf::Keyboard::A:
                        case sf::Keyboard::D:
                        case sf::Keyboard::Left:
                        case sf::Keyboard::Right:
                        {
                            move_check = true;
                            break;
                        }
                        case sf::Keyboard::W:
                        case sf::Keyboard::Up:
                        {
                            rotate_check = true;
                            break;
                        }
                        case sf::Keyboard::S:
                        case sf::Keyboard::Down:
                        {
                            move_faster_check = true;
                            break;
                        }
                        case sf::Keyboard::Space:
                        {
                            fall_check = true;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        if (move_check)
        {
            bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                         sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

            if (left && !right)
            {
                tetromino.move_left(matrix);
                move_check = false;
                move_clock.restart();
            }
            else if (right && !left)
            {
                tetromino.move_right(matrix);
                move_check = false;
                move_clock.restart();
            }
        }
        else
        {
            if (move_clock.getElapsedTime().asMilliseconds() >= MOVE_SPEED)
            {
                move_check = true;
            }
        }

        if (rotate_check)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                tetromino.rotate(matrix);
                rotate_check = false;
            }
        }

        if (move_faster_check)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                move_faster_check = false;
            }
        }

        if (fall_check)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                fall_check = false;
                while(!tetromino.move_down(matrix));
                tetromino.update_matrix(matrix);
                if (!tetromino.reset(0, matrix))
                {
                    score = 0;
                    for (int i = 0; i < COLUMNS; ++i)
                    {
                        for (int j = 0; j < ROWS; ++j)
                        {
                            matrix[i][j] = CC_GREY;
                        }
                    }
                }
                else {
                    score += Clear(matrix);
                }
            }
        }

        if (fall_clock.getElapsedTime().asMilliseconds() >
            (move_faster_check ? FALL_SPEED : FALL_FASTER_SPEED))
        {
            if (tetromino.move_down(matrix))
            {
                tetromino.update_matrix(matrix);
                if (!tetromino.reset(0, matrix))
                {
                    score = 0;
                    for (int i = 0; i < COLUMNS; ++i)
                    {
                        for (int j = 0; j < ROWS; ++j)
                        {
                            matrix[i][j] = CC_GREY;
                        }
                    }
                }
                else {
                    score += Clear(matrix);
                }
            }

            fall_clock.restart();
        }

        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

        window.clear();

        for (int i = 0; i < COLUMNS; ++i)
        {
            for (int j = 0; j < ROWS; ++j)
            {
                cell.setFillColor(GetColor(matrix[i][j]));

                cell.setPosition(i * CELL_SIZE + 0.5f, j * CELL_SIZE + 0.5f);
                window.draw(cell);
            }
        }

        cell.setFillColor(GetColor(CC_GREY));

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cell.setPosition((COLUMNS + 1 + i) * CELL_SIZE + 0.5f,
                                 (1 + j) * CELL_SIZE + 0.5f);
                window.draw(cell);
            }
        }



        cell.setFillColor(sf::Color(100, 100, 100));

        for (const sf::Vector2<char>& mino : tetromino.get_shadow())
		{
			cell.setPosition(static_cast<float>(CELL_SIZE * mino.x + 0.5f),
			                 static_cast<float>(CELL_SIZE * mino.y + 0.5f));

			window.draw(cell);
		}

        cell.setFillColor(GetColor(tetromino.get_color()));

        for (const sf::Vector2<char>& mino : tetromino.get_minos())
		{
			cell.setPosition(static_cast<float>(CELL_SIZE * mino.x + 0.5f),
			                 static_cast<float>(CELL_SIZE * mino.y + 0.5f));

			window.draw(cell);
		}

		cell.setFillColor(GetColor(tetromino.get_next_color()));

        for (const sf::Vector2<char>& mino : tetromino.get_next_minos())
        {
            cell.setPosition(static_cast<float>(CELL_SIZE * mino.x + NEXT_X + 0.5f),
                             static_cast<float>(CELL_SIZE * mino.y + NEXT_Y + 0.5f));

            window.draw(cell);
        }

        score_text.setString(std::to_string(score));
        window.draw(score_text);

        window.display();
        ++fps_count;
    }

    return 0;
}
