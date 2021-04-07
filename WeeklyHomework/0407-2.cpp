#include "math.h"
#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    double number[1001];
    double bin[1001] = {0};
    bool complete = 0;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        std::cin >> number[i];
        for (int j = 0; j <= sum; j++)
        {
            if (bin[j] + number[i] <= 1)
            {
                bin[j] = bin[j] + number[i];
                complete = 1;
                break;
            }
        }
        if (!complete)
        {
            sum += 1;
            bin[sum] = number[i];
        }
        complete = 0;
    }
    sum += 1;
    std::cout << sum << std::endl;
}