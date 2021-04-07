#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int numtree[257] = {0};
        char inputchar, temp = '(';
        string tempstring = "";
        int inputnum;
        int indexnum = 1;
        bool treecomplete = 1;
        cin >> inputchar;
        while (!(inputchar == ')' && temp == '('))
        {
            if (inputchar == 'L')
            {
                indexnum = indexnum * 2;
            }
            else if (inputchar == 'R')
            {
                indexnum = indexnum * 2 + 1;
            }
            else if (inputchar == ',')
            {
                inputnum = stoi(tempstring);
            }
            else if (inputchar == ')')
            {
                if (!numtree[indexnum])
                {
                    numtree[indexnum] = inputnum;
                    tempstring = "";
                }
                else
                {
                    treecomplete = 0;
                    break;
                }
                indexnum = 1;
            }
            else if (inputchar != ' ' && inputchar != '(')
            {
                tempstring += inputchar;
            }
            temp = inputchar;
            cin >> inputchar;
        }
        for (int i = 2; i <= 256; i++)
        {
            if (!numtree[i / 2] && numtree[i])
            {
                treecomplete = 0;
                break;
            }
        }
        if (!treecomplete)
        {
            cout << "not complete" << endl;
            continue;
        }
        else
        {
            for (int i = 1; i <= 256; i++)
            {
                if (i == 1 && numtree[i])
                {
                    cout << numtree[i];
                }
                else if (numtree[i])
                {
                    cout << " " << numtree[i];
                }
            }
            cout << endl;
        }
    }
    //system("pause");
}