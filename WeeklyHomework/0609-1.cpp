#include <cstring>
#include <iostream>

int main()
{
    int num;
    int idx = 0;
    while (std::cin >> num)
    {
        idx += 1;
        int sum = 0;
        for (int i = 0; i < num; i++)
        {
            std::string tmp;
            std::cin >> tmp;
            int table[26] = {0};
            int state = 1;
            for (int j = 0; j < tmp.length(); j++)
            {
                table[tmp[j] - 'a'] += 1;
            }
            /*
            for (int j = 0; j < 26; j++)
            {
                printf("%d ", table[j]);
            }
            */
            int counetr = 0;
            for (int j = 0; j < 26 && state == 1; j++)
            {
                if (table[j] != 0)
                {
                    counetr += 1;
                }
                if (counetr >= 2)
                {
                    break;
                }
            }
            if (counetr < 2)
            {
                state = 0;
            }
            for (int j = 0; j < 26 && state == 1; j++)
            {
                if (table[j] == 0)
                {
                    continue;
                }
                for (int k = 0; k < 26 && state == 1; k++)
                {
                    if (table[k] == 0)
                    {
                        continue;
                    }
                    if (table[j] == table[k] && j != k)
                    {
                        state = 0;
                    }
                }
            }
            if (state == 1)
            {
                sum += 1;
            }
        }
        printf("Case %d: %d\n", idx, sum);
    }
    return 0;
}