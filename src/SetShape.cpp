#include "Headers/SetShape.hpp"
#include "Headers/Global.hpp"

unsigned char SetShape(unsigned char shape, std::vector<sf::Vector2<char>>& minos)
{
    switch (shape)
    {
        /*
            # #
            # #
        */
        case 0:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2 - 1, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2, 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2 - 1, 1);
            minos[3] = sf::Vector2<char>(COLUMNS / 2, 1);
            break;
        }

        /*
            # # # #

        */
        case 1:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2 - 2, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2 - 1, 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2 , 0);
            minos[3] = sf::Vector2<char>(COLUMNS / 2 + 1, 0);
            break;
        }

        /*
            # # #
              #
        */
        case 2:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2 - 1, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2 , 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2 + 1 , 0);
            minos[3] = sf::Vector2<char>(COLUMNS / 2, 1);
            break;
        }

        /*
            # # #
                #
        */
        case 3:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2 - 1, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2 , 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2 + 1 , 0);
            minos[3] = sf::Vector2<char>(COLUMNS / 2 + 1, 1);
            break;
        }

        /*
            # # #
            #
        */
        case 4:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2 - 1, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2 , 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2 + 1 , 0);
            minos[3] = sf::Vector2<char>(COLUMNS / 2 - 1, 1);
            break;
        }

        /*
            # #
              # #
        */
        case 5:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2 - 1, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2, 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2, 1);
            minos[3] = sf::Vector2<char>(COLUMNS / 2 + 1, 1);
            break;
        }

        /*
              # #
            # #
        */
        case 6:
        {
            minos[0] = sf::Vector2<char>(COLUMNS / 2, 0);
            minos[1] = sf::Vector2<char>(COLUMNS / 2 + 1, 0);
            minos[2] = sf::Vector2<char>(COLUMNS / 2 - 1, 1);
            minos[3] = sf::Vector2<char>(COLUMNS / 2, 1);
            break;
        }
    }
    return shape;
}
