#include <iostream>
#include <string>
using namespace std;

int reversesum(int num);
bool check(int num);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int counter = 0;
        do
        {
            num = reversesum(num);
            counter += 1;
            if (counter > 1001)
            {
                break;
            }
        } while (!check(num));
        cout << counter << " " << num << endl;
    }
}

int reversesum(int num)
{
    string tmp = to_string(num);
    string reversetmp = "";
    for (int i = tmp.length() - 1; i >= 0; i--)
    {
        reversetmp += tmp.at(i);
    }
    int reversenum = stoi(reversetmp);
    return reversenum + num;
}

bool check(int num)
{
    string tmp = to_string(num);
    for (int i = 0; i < tmp.length() / 2; i++)
    {
        if (tmp.at(i) != tmp.at(tmp.length() - i - 1))
        {
            return false;
        }
    }
    return true;
}