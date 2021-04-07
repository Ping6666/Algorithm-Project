#include "math.h"
#include <iostream>

int dotmap[1001][2] = {{0}};
float distanceoftwopoint(int firnum, int secnum);
float trinum(int x, int y);

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dotmap[j][0] = 0;
            dotmap[j][1] = 0;
        }
        int N;
        std::cin >> N;
        for (int j = 0; j < N; j++)
        {
            std::cin >> dotmap[j][0] >> dotmap[j][1];
        }
        for (int j = 0; j < N; j++)
        {
            for (int k = j; k < N; k++)
            {
                if ((dotmap[j][0] > dotmap[k][0]) || (dotmap[j][0] == dotmap[k][0] && dotmap[j][1] > dotmap[k][1]))
                {
                    int tmpx = dotmap[j][0], tmpy = dotmap[j][1];
                    dotmap[j][0] = dotmap[k][0];
                    dotmap[j][1] = dotmap[k][1];
                    dotmap[k][0] = tmpx;
                    dotmap[k][1] = tmpy;
                }
            }
        }
        float D = distanceoftwopoint(0, N - 1);
        printf("%.3f\n", D);
    }
}

float trinum(int x, int y)
{
    return sqrt(pow((dotmap[x][0] - dotmap[y][0]), 2) + pow((dotmap[x][1] - dotmap[y][1]), 2));
}

float distanceoftwopoint(int firnum, int secnum)
{
    if ((secnum - firnum) == 1)
    {
        return trinum(secnum, firnum);
    }
    else
    {
        int med = (firnum + secnum) / 2;
        float left = distanceoftwopoint(firnum, med);
        float right = 100000;
        float tmp = 100000;
        float mednum = 100000;
        if (secnum - med > 1)
        {
            right = distanceoftwopoint(med + 1, secnum);
        }
        else
        {
            right = trinum(med, secnum);
        }
        for (int i = 1; i < 2; i++)
        {
            if (med + i < secnum)
            {
                tmp = trinum(med + 1, med + i + 1);
                if (tmp < mednum)
                {
                    mednum = tmp;
                }
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            if (med - i >= firnum)
            {
                tmp = trinum(med - i, med + 1);
                if (tmp < mednum)
                {
                    mednum = tmp;
                }
            }
            else
            {
                break;
            }
        }
        if (tmp < mednum)
        {
            mednum = tmp;
        }
        if (right > mednum)
        {
            right = mednum;
        }
        if (left < right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}