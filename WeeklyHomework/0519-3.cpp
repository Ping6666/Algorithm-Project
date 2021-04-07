#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num, idx;
        std::cin >> num >> idx;
        int xidx = 0, yidx = 0;
        int table[100][100] = {{0}};
        int len = 0;
        for (int j = 0; j < num / 2 + 1; j++)
        {
            for (int k = 0 + len; k < num - len; k++)
            {
                for (int l = 0 + len; l < num - len; l++)
                {
                    table[k][l] += 1;
                }
            }
            len += 1;
        }
        /*
        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                std::cout << table[j][k] << " ";
            }
            std::cout << std::endl;
        }
        */
        bool dir = 0;
        for (int j = 0; j < idx - 1; j++)
        {
            if (dir)
            {
                if (yidx - 1 < 0 && xidx + 1 > num - 1)
                {
                    yidx = 1;
                    xidx = num - 1;
                    dir = 0;
                }
                else if (xidx + 1 > num - 1)
                {
                    yidx = yidx + 1;
                    xidx = num - 1;
                    dir = 0;
                }
                else if (yidx - 1 < 0)
                {
                    xidx = xidx + 1;
                    yidx = 0;
                    dir = 0;
                }
                else
                {
                    xidx += 1;
                    yidx -= 1;
                }
            }
            else
            {
                if (xidx - 1 < 0 && yidx + 1 > num - 1)
                {
                    xidx = 1;
                    yidx = num - 1;
                    dir = 1;
                }
                else if (xidx - 1 < 0)
                {
                    yidx = yidx + 1;
                    xidx = 0;
                    dir = 1;
                }
                else if (yidx + 1 > num - 1)
                {
                    xidx = xidx + 1;
                    yidx = num - 1;
                    dir = 1;
                }
                else
                {
                    xidx -= 1;
                    yidx += 1;
                }
            }
            //std::cout << xidx << " " << yidx << " " << dir << std::endl;
        }
        std::cout << table[xidx][yidx] << std::endl;
    }
    return 0;
}