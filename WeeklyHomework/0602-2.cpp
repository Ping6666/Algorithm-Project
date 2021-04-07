#include <iostream>
#include <string>

bool primecheck(int n);

int numtable[10] = {0};
int eng0table[26] = {0};
int eng1table[26] = {0};

int main()
{
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        for (int j = 0; j < 10; j++)
        {
            numtable[j] = 0;
        }
        for (int j = 0; j < 26; j++)
        {
            eng0table[j] = 0;
            eng1table[j] = 0;
        }
        for (int j = 0; j < tmp.length(); j++)
        {
            if (tmp[j] >= '0' && tmp[j] <= '9')
            {
                numtable[tmp[j] - '0'] += 1;
            }
            else if (tmp[j] >= 'a' && tmp[j] <= 'z')
            {
                eng0table[tmp[j] - 'a'] += 1;
            }
            else if (tmp[j] >= 'A' && tmp[j] <= 'Z')
            {
                eng1table[tmp[j] - 'A'] += 1;
            }
        }

        bool check = 0;
        for (int j = 0; j < 10; j++)
        {
            if (primecheck(numtable[j]) && numtable[j] >= 2)
            {
                char tmp = j + '0';
                printf("%c", tmp);
                check = 1;
            }
        }
        for (int j = 0; j < 26; j++)
        {
            if (primecheck(eng1table[j]) && eng1table[j] >= 2)
            {
                char tmp = j + 'A';
                printf("%c", tmp);
                check = 1;
            }
        }
        for (int j = 0; j < 26; j++)
        {
            if (primecheck(eng0table[j]) && eng0table[j] >= 2)
            {
                char tmp = j + 'a';
                printf("%c", tmp);
                check = 1;
            }
        }
        if (check)
        {
            printf("\n");
        }
        else
        {
            printf("empty\n");
        }
    }
    return 0;
}

bool primecheck(int n)
{
    for (int i = 2; i < n / 2 + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}