#include "Headers/GetColor.hpp"
#include "Headers/Global.hpp"

sf::Color GetColor(unsigned char color_i)
{
    switch (color_i)
    {
        case (CC_GREY):
            return sf::Color(50, 50, 50);
            break;
        case (CC_RED):
            return sf::Color::Red;
            break;
        case (CC_GREEN):
            return sf::Color::Green;
            break;
        case (CC_BLUE):
            return sf::Color::Blue;
            break;
        case (CC_YELLOW):
            return sf::Color::Yellow;
            break;
        case (CC_MAGENTA):
            return sf::Color::Magenta;
            break;
        case (CC_CYAN):
            return sf::Color::Cyan;
            break;
    }
    return sf::Color::Black;
}
