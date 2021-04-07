#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        std::cin >> a >> b;
        int sum = 0;
        for (int j = a; j < b + 1; j++)
        {
            if (j % 2 == 1)
            {
                sum += j;
            }
        }
        printf("Case %d: %d\n", i + 1, sum);
    }
    return 0;
}