#include <iostream>

int main()
{
    int table[1001];
    int num = 0;
    for (int i = 1; num < 1001; i++)
    {
        int tmp = i;
        while (tmp % 2 == 0 || tmp % 3 == 0 || tmp % 5 == 0)
        {
            if (tmp % 2 == 0)
            {
                tmp /= 2;
            }
            else if (tmp % 3 == 0)
            {
                tmp /= 3;
            }
            else if (tmp % 5 == 0)
            {
                tmp /= 5;
            }
        }
        if (tmp == 1)
        {
            table[num] = i;
            num += 1;
        }
    }
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int n;
        std::cin >> n;
        std::cout << table[n - 1] << std::endl;
    }
    return 0;
}