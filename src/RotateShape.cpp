#include "Headers/RotateShape.hpp"

void RotateShape(unsigned char rotation, unsigned char shape, std::vector<sf::Vector2<char>>& minos)
{
    switch (shape)
    {
        /*
            0 1
            2 3
        */
        case 0:
        {
            break;
        }

        /*
            0 1 2 3

        */
        case 1:
        {
            switch (rotation)
            {
                case 0:
                    minos[3] = sf::Vector2<char>(minos[2].x, minos[2].y + 1);
                    minos[1] = sf::Vector2<char>(minos[2].x, minos[2].y - 1);
                    minos[0] = sf::Vector2<char>(minos[2].x, minos[2].y - 2);
                    break;
                case 1:
                    minos[3] = sf::Vector2<char>(minos[2].x - 1, minos[2].y);
                    minos[1] = sf::Vector2<char>(minos[2].x + 1, minos[2].y);
                    minos[0] = sf::Vector2<char>(minos[2].x + 2, minos[2].y);
                    break;
                case 2:
                    minos[3] = sf::Vector2<char>(minos[2].x, minos[2].y - 1);
                    minos[1] = sf::Vector2<char>(minos[2].x, minos[2].y + 1);
                    minos[0] = sf::Vector2<char>(minos[2].x, minos[2].y + 2);
                    break;
                case 3:
                    minos[3] = sf::Vector2<char>(minos[2].x + 1, minos[2].y);
                    minos[1] = sf::Vector2<char>(minos[2].x - 1, minos[2].y);
                    minos[0] = sf::Vector2<char>(minos[2].x - 2, minos[2].y);
                    break;
                default:
                    break;
            }

            break;
        }

        /*
            0 1 2
              3
        */
        case 2:
        {
            switch (rotation)
            {
                case 0:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    break;
                case 1:
                    minos[0] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    break;
                case 2:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    break;
                case 3:
                    minos[0] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    break;
                default:
                    break;
            }

            break;
        }

        /*
            0 1 2
                3
        */
        case 3:
        {
            switch (rotation)
            {
                case 0:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y + 1);
                    break;
                case 1:
                    minos[0] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y - 1);
                    break;
                case 2:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y - 1);
                    break;
                case 3:
                    minos[0] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y + 1);
                    break;
                default:
                    break;
            }

            break;
        }

        /*
            0 1 2
            3
        */
        case 4:
        {
            switch (rotation)
            {
                case 0:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y - 1);
                    break;
                case 1:
                    minos[0] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y - 1);
                    break;
                case 2:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y + 1);
                    break;
                case 3:
                    minos[0] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y + 1);
                    break;
                default:
                    break;
            }

            break;
        }

        /*
            0 1
              2 3
        */
        case 5:
        {
            switch (rotation)
            {
                case 0:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[2] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y + 1);
                    break;
                case 1:
                    minos[0] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y - 1);
                    minos[3] = sf::Vector2<char>(minos[1].x - 1, minos[1].y - 1);
                    break;
                case 2:
                    minos[0] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[2] = sf::Vector2<char>(minos[1].x + 1, minos[1].y);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y - 1);
                    break;
                case 3:
                    minos[0] = sf::Vector2<char>(minos[1].x - 1, minos[1].y);
                    minos[2] = sf::Vector2<char>(minos[1].x, minos[1].y + 1);
                    minos[3] = sf::Vector2<char>(minos[1].x + 1, minos[1].y + 1);
                    break;
                default:
                    break;
            }

            break;
        }

        /*
              0 1
            2 3
        */
        case 6:
        {
            switch (rotation)
            {
                case 0:
                    minos[1] = sf::Vector2<char>(minos[0].x, minos[0].y + 1);
                    minos[2] = sf::Vector2<char>(minos[0].x - 1, minos[0].y - 1);
                    minos[3] = sf::Vector2<char>(minos[0].x - 1, minos[0].y);
                    break;
                case 1:
                    minos[1] = sf::Vector2<char>(minos[0].x - 1, minos[0].y);
                    minos[2] = sf::Vector2<char>(minos[0].x + 1, minos[0].y - 1);
                    minos[3] = sf::Vector2<char>(minos[0].x, minos[0].y - 1);
                    break;
                case 2:
                    minos[1] = sf::Vector2<char>(minos[0].x, minos[0].y - 1);
                    minos[2] = sf::Vector2<char>(minos[0].x + 1, minos[0].y + 1);
                    minos[3] = sf::Vector2<char>(minos[0].x + 1, minos[0].y);
                    break;
                case 3:
                    minos[1] = sf::Vector2<char>(minos[0].x + 1, minos[0].y);
                    minos[2] = sf::Vector2<char>(minos[0].x - 1, minos[0].y + 1);
                    minos[3] = sf::Vector2<char>(minos[0].x, minos[0].y + 1);
                    break;
                default:
                    break;
            }

            break;
        }
    }
}
