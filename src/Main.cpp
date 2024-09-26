#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <ctime>

#include "Headers/Global.hpp"
#include "Headers/GetColor.hpp"
#include "Headers/Tetromino.hpp"

int main()
{
    std::srand(std::time(nullptr));

    sf::Event event;

    sf::Clock fps_clock;
    int fps_count = 0;

    std::vector<std::vector<unsigned char>> matrix(COLUMNS, std::vector<unsigned char>(ROWS, CC_GREY));

    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_RESIZE, CELL_SIZE * ROWS * SCREEN_RESIZE), sf::String("FPS: 0"));
    window.setVerticalSyncEnabled(true);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));

    Tetromino tetromino(0);
    sf::Clock fall_clock;

    bool move_check = true;
    sf::Clock move_clock;

    bool rotate_check = true;

    while (window.isOpen())
    {
        if (fps_clock.getElapsedTime().asMilliseconds() > 1000)
        {
            window.setTitle("FPS: " + std::to_string(fps_count));
            fps_count = 0;
            fps_clock.restart();
        }
        if (fall_clock.getElapsedTime().asMilliseconds() > FALL_SPEED)
        {
            if (tetromino.move_down(matrix))
            {
                tetromino.update_matrix(matrix);
                if (!tetromino.reset(0, matrix))
                {
                    for (int i = 0; i < COLUMNS; ++i)
                    {
                        for (int j = 0; j < ROWS; ++j)
                        {
                            matrix[i][j] = CC_GREY;
                        }
                    }
                }
            }

            fall_clock.restart();
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

        cell.setFillColor(GetColor(tetromino.get_color()));

        for (const sf::Vector2<char>& mino : tetromino.get_minos())
		{
			cell.setPosition(static_cast<float>(CELL_SIZE * mino.x + 0.5f), static_cast<float>(CELL_SIZE * mino.y + 0.5f));

			window.draw(cell);
		}

        window.display();
        ++fps_count;
    }

    return 0;
}
