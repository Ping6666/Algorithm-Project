#include <iostream>
#include <string>

int main()
{
    std::string s, t;
    while(std::cin >> s)
    {
        std::cin >> t;
        int slen = s.length();
        int tlen = t.length();
        int sidx = 0, tidx = 0;
        bool state = 0;
        while (sidx < slen && tidx < tlen)
        {
            if (s[sidx] == t[tidx])
            {
                sidx += 1;
                tidx += 1;
                if (sidx == slen)
                {
                    state = 1;
                }
            }
            else
            {
                tidx += 1;
            }
        }
        if (state)
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}