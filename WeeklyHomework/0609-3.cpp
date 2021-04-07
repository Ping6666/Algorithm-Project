#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a < b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        int num = a % b;
        while (num > 0)
        {
            a = b;
            b = num;
            num = a % b;
        }
        std::cout << b << std::endl;
    }
    return 0;
}