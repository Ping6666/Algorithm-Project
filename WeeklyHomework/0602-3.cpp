#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a == b)
        {
            printf("=\n");
        }
        else if (a > b)
        {
            printf(">\n");
        }
        else
        {
            printf("<\n");
        }
    }
    return 0;
}