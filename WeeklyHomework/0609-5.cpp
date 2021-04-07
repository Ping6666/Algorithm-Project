#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        unsigned long long int n;
        std::cin >> n;
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        bool state = 0;
        std::string tmps = "";
        int idx = 0;
        int j = 9;
        while (j > 0 && state == 0)
        {
            if (n % j == 0 && state == 0)
            {
                tmps += j + '0';
                n /= j;
                idx += 1;
                if (n == 1)
                {
                    state = 1;
                    break;
                }
                else if (j == 1 && tmps != "")
                {
                    break;
                }
            }
            else
            {
                j -= 1;
            }
        }
        if (state == 1 && tmps != "")
        {

            for (int j = tmps.length() - 1; j >= 0; j--)
            {
                std::cout << tmps[j];
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}