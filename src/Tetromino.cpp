#include "Headers/Global.hpp"
#include "Headers/SetShape.hpp"
#include "Headers/Tetromino.hpp"
#include "Headers/Clear.hpp"
#include "Headers/RotateShape.hpp"
#include <SFML/System/Vector2.hpp>


Tetromino::Tetromino(unsigned char shape)
{
    m_color = 1;
    m_rotation = 0;
    m_minos.resize(4);
    m_shape = SetShape(rand() % 7, m_minos);
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
    return false;
}

void Tetromino::rotate(const std::vector<std::vector<unsigned char>>& matrix)
{
    std::vector<sf::Vector2<char>> minos = m_minos;
    RotateShape(m_rotation, m_shape, minos);
    m_rotation = (m_rotation + 1) % 4;
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
}

bool Tetromino::reset(unsigned char shape, std::vector<std::vector<unsigned char>>& matrix)
{
    m_color = rand() % (CELL_COLORS_SIZE - 1) + 1;
    m_rotation = 0;
    m_shape = SetShape(rand() % 7, m_minos);
    for (sf::Vector2<char>& mino : m_minos)
    {
        if (matrix[mino.x][mino.y] != 0)
        {
            return 0;
        }
    }
    Clear(matrix);
    return 1;
}

void Tetromino::update_matrix(std::vector<std::vector<unsigned char>>& matrix)
{
    for (sf::Vector2<char>& mino : m_minos)
	{
		matrix[mino.x][mino.y] = m_color;
	}
}

std::vector<sf::Vector2<char>> Tetromino::get_minos()
{
    return m_minos;
}

unsigned char Tetromino::get_color()
{
    return m_color;
}
