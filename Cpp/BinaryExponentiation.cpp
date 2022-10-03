#include <bits/stdc++.h>
using namespace std;

long long power(long long num, long long pw)
{
    long long res = 1;
    while (pw)
    {
        if (pw & 1)
            res *= num;
        num *= num;
        pw >>= 1;
    }
    return res;
}

const int MOD = 1e9 + 7;
long long mod_pow(long long num, long long pw)
{
    long long res = 1;
    while (pw)
    {
        if (pw & 1)
        {
            res *= num;
            res %= MOD;
        }
        num *= num;
        num %= MOD;
        pw >>= 1;
    }
    return res;
}

int main()
{
    long long num, pw;
    cin >> num >> pw;
    cout << power(num, pw) << endl;
    cout << mod_pow(num, pw) << endl;
    return 0;
}