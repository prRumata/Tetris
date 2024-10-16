#include "Headers/Clear.hpp"
#include "Headers/Global.hpp"

int Clear(std::vector<std::vector<unsigned char>>& matrix)
{
    bool flag;
    unsigned char count = 0;
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
            ++count;
            for (int i = y; i > 0; --i)
            {
                for (int j = 0; j < COLUMNS; ++j)
                {
                    matrix[j][i] = matrix[j][i - 1];
                }
            }
        }
    }

    switch (count)
    {
        case 0:
            return 0;
            break;
        case 1:
            return 100;
            break;
        case 2:
            return 300;
            break;
        case 3:
            return 700;
            break;
        case 4:
            return 1500;
            break;
    }
    return 0;
}
