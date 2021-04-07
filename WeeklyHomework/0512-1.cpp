#include <iostream>
#define numbers 5
#define maxnumber 100

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int maxnum;
        int items[numbers + 1][2]; //0表重量，1表價值
        std::cin >> maxnum;
        for (int j = 1; j <= numbers; j++)
        {
            std::cin >> items[j][0];
        }
        for (int j = 1; j <= numbers; j++)
        {
            std::cin >> items[j][1];
        }
        int price[numbers + 1][maxnumber + 1] = {{0}};
        for (int x = 1; x <= numbers; x++)
        {
            for (int y = 0; y <= maxnum; y++)
            {
                if (items[x][0] <= y)
                {
                    price[x][y] = std::max(price[x - 1][y], items[x][1] + price[x - 1][y - items[x][0]]);
                }
                else
                {
                    price[x][y] = price[x - 1][y];
                }
            }
        }
        std::cout << price[numbers][maxnum] << std::endl;
    }
    return 0;
}