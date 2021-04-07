#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int N;
        std::cin >> N;
        int numbers[1001];
        for (int j = 0; j < N; j++)
        {
            std::cin >> numbers[j];
        }
        int max = -10000000;
        for (int j = 0; j < N; j++)
        {
            int sum = numbers[j];
            if (max < sum)
            {
                max = sum;
            }
            for (int k = j + 1; k < N; k++)
            {
                sum += numbers[k];
                if (max < sum)
                {
                    max = sum;
                }
            }
        }
        std::cout << max << std::endl;
    }
}