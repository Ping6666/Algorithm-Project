#include <iostream>
#include <string>

int main()
{
    long long int num;
    std::cin >> num;
    std::string tmp = "";
    while (num >= 0)
    {
        if (num == 0)
        {
            tmp = "0";
        }
        else
        {
            while (num > 0)
            {
                char tmpc = num % 3 + 48;
                tmp += tmpc;
                num /= 3;
            }
        }
        for (int i = tmp.length() - 1; i >= 0; i--)
        {
            std::cout << tmp[i];
        }
        std::cout << std::endl;
        std::cin >> num;
        tmp = "";
    }
    return 0;
}