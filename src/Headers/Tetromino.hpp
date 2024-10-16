#pragma once

#include <SFML/System.hpp>
#include <vector>

class Tetromino
{
private:
    std::vector<sf::Vector2<char>> m_minos;
    std::vector<sf::Vector2<char>> m_shadow;
    std::vector<sf::Vector2<char>> m_next_minos;
    unsigned char m_color;
    unsigned char m_next_color;
    unsigned char m_shape;
    unsigned char m_next_shape;
    unsigned char m_rotation;
public:
    Tetromino(unsigned char shape);

    bool move_down(const std::vector<std::vector<unsigned char>>& matrix);
    bool move_left(const std::vector<std::vector<unsigned char>>& matrix);
    bool move_right(const std::vector<std::vector<unsigned char>>& matrix);
    void rotate(const std::vector<std::vector<unsigned char>>& matrix);

    bool reset(unsigned char shape, std::vector<std::vector<unsigned char>>& matrix);
    void update_matrix(std::vector<std::vector<unsigned char>>& matrix);
    void update_shadow(const std::vector<std::vector<unsigned char>>& matrix);

    std::vector<sf::Vector2<char>> get_minos();
    std::vector<sf::Vector2<char>> get_shadow();
    std::vector<sf::Vector2<char>> get_next_minos();
    unsigned char get_color();
    unsigned char get_next_color();
};
