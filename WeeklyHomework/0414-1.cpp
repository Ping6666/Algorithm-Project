#include "math.h"
#include <iostream>
#include <vector>
using namespace std;

typedef int64_t ll;
typedef long long ll;

const int base = 1e9;
typedef vector<int> BigInt;

void Set(BigInt &a)
{
    while (a.size() > 1 && a.back() == 0)
    {
        a.pop_back();
    }
}

void Print(BigInt a)
{
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    for (int i = a.size() - 2; i >= 0; i--)
    {
        printf("%09d", a[i]);
    }
    printf("\n");
}

BigInt Integer(string s)
{
    BigInt ans;
    if (s[0] == '-')
    {
        return ans;
    }
    if (s.size() == 0)
    {
        ans.push_back(0);
        return ans;
    }
    while (s.size() % 9 != 0)
    {
        s = '0' + s;
    }
    for (int i = 0; i < s.size(); i += 9)
    {
        int t = 0;
        for (int j = i; j < i + 9; j++)
        {
            t = t * 10 + (s[j] - '0');
        }
        ans.insert(ans.begin(), t);
    }
    Set(ans);
    return ans;
}

BigInt Integer(ll x)
{
    string s = "";
    while (x > 0)
    {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    return Integer(s);
}

BigInt Integer(int x)
{
    return Integer((ll)x);
}

BigInt operator+(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    int carry = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++)
    {
        if (i < a.size())
        {
            carry += a[i];
        }
        if (i < b.size())
        {
            carry += b[i];
        }
        ans.push_back(carry % base);
        carry /= base;
    }
    if (carry)
    {
        ans.push_back(carry);
    }
    Set(ans);
    return ans;
}

BigInt operator*(BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        ll carry = 0ll;
        for (int j = 0; j < b.size() || carry > 0; j++)
        {
            ll s = ans[i + j] + carry + (ll)a[i] * (j < b.size() ? (ll)b[j] : 0ll);
            ans[i + j] = s % base;
            carry = s / base;
        }
    }
    Set(ans);
    return ans;
}

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        BigInt A = Integer(1), B = Integer(1);
        while (a >= 30)
        {
            A = A * Integer(int(pow(2, 30)));
            a -= 30;
        }
        if (a)
        {
            A = A * Integer(int(pow(2, a)));
        }
        while (b >= 30)
        {
            B = B * Integer(int(pow(2, 30)));
            b -= 30;
        }
        if (b)
        {
            B = B * Integer(int(pow(2, b)));
        }
        A = A + B;
        Print(A);
    }
}