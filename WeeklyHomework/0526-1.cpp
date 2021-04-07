#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int n;
        std::cin >> n;
        int sum = 0;
        int num = 0;
        for (int j = 1; sum <= n; j++)
        {
            sum += j;
            num = j;
        }
        std::cout << sum - n << " " << num << std::endl;
    }
    return 0;
}