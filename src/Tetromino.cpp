#include "Headers/Global.hpp"
#include "Headers/SetShape.hpp"
#include "Headers/Tetromino.hpp"
#include "Headers/RotateShape.hpp"
#include <SFML/System.hpp>


Tetromino::Tetromino(unsigned char shape)
{
    m_color = 1;
    m_next_color = 2;
    m_rotation = 0;
    m_minos.resize(4);
    m_next_minos.resize(4);
    m_shape = SetShape(rand() % 7, m_minos);
    m_next_shape = SetShape(rand() % 7, m_next_minos);
}

bool Tetromino::move_down(const std::vector<std::vector<unsigned char>>& matrix)
{
    for (sf::Vector2<char>& mino : m_minos)
    {
        if (mino.y + 1 == ROWS)
        {
            return 1;
        }
        if (matrix[mino.x][mino.y + 1] != 0)
        {
            return 1;
        }
    }

    for (sf::Vector2<char>& mino : m_minos)
    {
        ++mino.y;
    }
    update_shadow(matrix);
    return 0;
}

bool Tetromino::move_left(const std::vector<std::vector<unsigned char>>& matrix)
{
    for (sf::Vector2<char>& mino : m_minos)
    {
        if (mino.x - 1 < 0)
        {
            return true;
        }
        if (matrix[mino.x - 1][mino.y] != 0)
        {
            return true;
        }
    }

    for (sf::Vector2<char>& mino : m_minos)
    {
        --mino.x;
    }
    update_shadow(matrix);
    return false;
}

bool Tetromino::move_right(const std::vector<std::vector<unsigned char>>& matrix)
{
    for (sf::Vector2<char>& mino : m_minos)
    {
        if (mino.x + 1 == COLUMNS)
        {
            return true;
        }
        if (matrix[mino.x + 1][mino.y] != 0)
        {
            return true;
        }
    }

    for (sf::Vector2<char>& mino : m_minos)
    {
        ++mino.x;
    }
    update_shadow(matrix);
    return false;
}

void Tetromino::rotate(const std::vector<std::vector<unsigned char>>& matrix)
{
    std::vector<sf::Vector2<char>> minos = m_minos;
    RotateShape(m_rotation, m_shape, minos);
    for (sf::Vector2<char>& mino : minos)
    {
        if (mino.x < 0)
        {
            if (mino.x < -1)
            {
                for (sf::Vector2<char>& mino : minos)
                {
                    ++mino.x;
                }
            }
            for (sf::Vector2<char>& mino : minos)
            {
                ++mino.x;
            }
        }
        else if (mino.x >= COLUMNS)
        {
            if (mino.x > COLUMNS)
            {
                for (sf::Vector2<char>& mino : minos)
                {
                    --mino.x;
                }
            }
            for (sf::Vector2<char>& mino : minos)
            {
                --mino.x;
            }
        }
    }
    for (sf::Vector2<char>& mino : minos)
    {
        if (matrix[mino.x][mino.y] != 0)
        {
            return;
        }
    }
    m_minos = minos;
    m_rotation = (m_rotation + 1) % 4;

    update_shadow(matrix);
}

bool Tetromino::reset(unsigned char shape, std::vector<std::vector<unsigned char>>& matrix)
{
    m_color = m_next_color;
    m_next_color = rand() % (CELL_COLORS_SIZE - 1) + 1;
    m_rotation = 0;
    for (int i = 0; i < 4; ++i)
    {
        m_minos[i].x = m_next_minos[i].x;
        m_minos[i].y = m_next_minos[i].y;
    }
    m_shape = m_next_shape;
    m_next_shape = SetShape(rand() % 7, m_next_minos);
    update_shadow(matrix);
    for (sf::Vector2<char>& mino : m_minos)
    {
        if (matrix[mino.x][mino.y] != 0)
        {
            return 0;
        }
    }
    for (int i = 0; i < COLUMNS; ++i)
    {
        if (matrix[i][0] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void Tetromino::update_matrix(std::vector<std::vector<unsigned char>>& matrix)
{
    for (sf::Vector2<char>& mino : m_minos)
	{
		matrix[mino.x][mino.y] = m_color;
	}
}

void Tetromino::update_shadow(const std::vector<std::vector<unsigned char>>& matrix)
{
    m_shadow = m_minos;

    while (true)
    {
        for (sf::Vector2<char>& mino : m_shadow)
        {
            if (mino.y + 1 == ROWS)
            {
                return;
            }
            if (matrix[mino.x][mino.y + 1] != 0)
            {
                return;
            }
        }

        for (sf::Vector2<char>& mino : m_shadow)
        {
            ++mino.y;
        }
    }
}

std::vector<sf::Vector2<char>> Tetromino::get_minos()
{
    return m_minos;
}

std::vector<sf::Vector2<char>> Tetromino::get_shadow()
{
    return m_shadow;
}

std::vector<sf::Vector2<char>> Tetromino::get_next_minos()
{
    return m_next_minos;
}

unsigned char Tetromino::get_color()
{
    return m_color;
}

unsigned char Tetromino::get_next_color()
{
    return m_next_color;
}
