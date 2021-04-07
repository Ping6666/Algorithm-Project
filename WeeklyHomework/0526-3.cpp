#include <iostream>
#include <math.h>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string s, t;
        std::cin >> s;
        std::cin >> t;
        int table[101][101] = {{0}};
        int slen = s.length();
        int tlen = t.length();
        for (int j = 1; j <= slen; j++)
        {
            for (int k = 1; k <= tlen; k++)
            {
                if (s[j - 1] == t[k - 1])
                {
                    table[j][k] = table[j - 1][k - 1] + 1;
                }
                else if (table[j - 1][k] >= table[j][k - 1])
                {
                    table[j][k] = table[j - 1][k];
                }
                else
                {
                    table[j][k] = table[j][k - 1];
                }
            }
        }
        std::cout << table[slen][tlen] << std::endl;
    }
    return 0;
}