#include "Headers/Clear.hpp"
#include "Headers/Global.hpp"

void Clear(std::vector<std::vector<unsigned char>>& matrix)
{
    bool flag;
    for (int y = 0; y < ROWS; ++y)
    {
        flag = true;
        for (int x = 0; x < COLUMNS; ++x)
        {
            if (matrix[x][y] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = y; i > 0; --i)
            {
                for (int j = 0; j < COLUMNS; ++j)
                {
                    matrix[j][i] = matrix[j][i - 1];
                }
            }
        }
    }
}
