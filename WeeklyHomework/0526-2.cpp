#include <iostream>
#include <math.h>

int main()
{
    int table[24];
    for (int i = 0; i < 24; i++)
    {
        std::cin >> table[i];
    }
    int bigtable[10];
    int minidx, minnum = 1000000;
    for (int j = 0; j < 3; j++)
    {
        bigtable[j] = table[j];
        if (bigtable[j] < minnum)
        {
            minnum = bigtable[j];
            minidx = j + 1;
        }
    }
    std::cout << minidx << " " << minnum << std::endl;
    for (int i = 1; i < 3; i++)
    {
        minnum = 1000000;
        for (int j = 0; j < 3; j++)
        {
            int tmp[3];
            for (int k = 0; k < 3; k++)
            {
                tmp[k] = bigtable[(i - 1) * 3 + k] + table[(i - 1) * 9 + j + (k + 1) * 3];
            }
            bigtable[i * 3 + j] = std::min(std::min(tmp[0], tmp[1]), tmp[2]);
            if (bigtable[i * 3 + j] < minnum)
            {
                minnum = bigtable[i * 3 + j];
                minidx = i * 3 + j + 1;
            }
        }
        std::cout << minidx << " " << minnum << std::endl;
    }
    int tmp[3];
    tmp[0] = bigtable[6] + table[21];
    tmp[1] = bigtable[7] + table[22];
    tmp[2] = bigtable[8] + table[23];
    bigtable[9] = std::min(std::min(tmp[0], tmp[1]), tmp[2]);
    std::cout << 10 << " " << bigtable[9] << std::endl;
    return 0;
}