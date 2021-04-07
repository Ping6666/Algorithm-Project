#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        int table[1000];
        int sum = 0;
        for (int j = 0; j < num; j++)
        {
            std::cin >> table[j];
            sum += table[j];
        }
        sum /= num;
        int tmp = 0;
        for (int j = 0; j < num; j++)
        {
            if (table[j] - sum > 0)
            {
                tmp += table[j] - sum;
            }
        }
        std::cout << tmp << std::endl;
    }
    return 0;
}