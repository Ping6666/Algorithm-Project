#include "math.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int j = 0; j < num; j++)
    {
        string instring = "";
        cin >> instring;
        int number0 = 0, number1 = 0;
        string tempstring = "";
        int tempint = 0;
        bool position = 0; //0表左邊
        bool positive = 0; //0表正數
        for (int i = 0; i >= 0; i++)
        {
            if (instring[i] == '\0')
            {
                if (tempstring == "")
                {
                    tempint = 0;
                }
                else
                {
                    tempint = stoi(tempstring);
                }
                if (position == 0)
                {
                    if (positive == 0)
                    {
                        number0 += tempint;
                    }
                    else
                    {
                        number0 -= tempint;
                    }
                }
                else
                {
                    if (positive == 0)
                    {
                        number0 -= tempint;
                    }
                    else
                    {
                        number0 += tempint;
                    }
                }
                break;
            }
            else if (instring[i] == 'x')
            {
                if (tempstring == "")
                {
                    tempint = 1;
                }
                else
                {
                    tempint = stoi(tempstring);
                }
                if (position == 0)
                {
                    if (positive == 0)
                    {
                        number1 += tempint;
                    }
                    else
                    {
                        number1 -= tempint;
                    }
                }
                else
                {
                    if (positive == 0)
                    {
                        number1 -= tempint;
                    }
                    else
                    {
                        number1 += tempint;
                    }
                }
                positive = 0;
                tempstring = "";
            }
            else if (instring[i] == '=')
            {
                if (tempstring == "")
                {
                    tempint = 0;
                }
                else
                {
                    tempint = stoi(tempstring);
                }
                if (position == 0)
                {
                    if (positive == 0)
                    {
                        number0 += tempint;
                    }
                    else
                    {
                        number0 -= tempint;
                    }
                }
                else
                {
                    if (positive == 0)
                    {
                        number0 -= tempint;
                    }
                    else
                    {
                        number0 += tempint;
                    }
                }
                position = 1;
                positive = 0;
                tempstring = "";
            }
            else if (instring[i] == '+')
            {
                if (tempstring == "")
                {
                    tempint = 0;
                }
                else
                {
                    tempint = stoi(tempstring);
                }
                if (position == 0)
                {
                    if (positive == 0)
                    {
                        number0 += tempint;
                    }
                    else
                    {
                        number0 -= tempint;
                    }
                }
                else
                {
                    if (positive == 0)
                    {
                        number0 -= tempint;
                    }
                    else
                    {
                        number0 += tempint;
                    }
                }
                tempstring = "";
                positive = 0;
            }
            else if (instring[i] == '-')
            {
                if (tempstring == "")
                {
                    tempint = 0;
                }
                else
                {
                    tempint = stoi(tempstring);
                }
                if (position == 0)
                {
                    if (positive == 0)
                    {
                        number0 += tempint;
                    }
                    else
                    {
                        number0 -= tempint;
                    }
                }
                else
                {
                    if (positive == 0)
                    {
                        number0 -= tempint;
                    }
                    else
                    {
                        number0 += tempint;
                    }
                }
                tempstring = "";
                positive = 1;
            }
            else
            {
                tempstring += instring[i];
            }
        }
        number1 = -number1;
        if (number0 != 0 && number1 == 0)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else if (number0 == 0 && number1 == 0)
        {
            cout << "IDENTITY" << endl;
        }
        else
        {
            cout << floor(double(number0) / number1) << endl;
        }
    }
}