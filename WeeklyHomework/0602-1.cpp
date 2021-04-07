#include <iostream>

bool perfectcheck(int n);

int main()
{
    int num;
    std::cin >> num;
    //bool check = 0;
    for (int i = 0; i < num; i++)
    {
        int n;
        std::cin >> n;
        if (perfectcheck(n))
        {
            /*
            if (check)
            {
                printf(" %d", n);
            }
            else
            {
                printf("%d", n);
                check = 1;
            }
            */
            printf("%d ", n);
        }
    }
    printf("\n");
    return 0;
}

bool perfectcheck(int n)
{
    int num = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            num += i;
        }
    }

    if (num == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}