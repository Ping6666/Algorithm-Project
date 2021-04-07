#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int n, k;
        std::cin >> n >> k;
        int sum = n;
        int tmp = n;
        while (tmp >= k)
        {
            sum += tmp / k;
            tmp = tmp / k + tmp % k;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}