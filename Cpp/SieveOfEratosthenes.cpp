#include <bits/stdc++.h>
using namespace std;

int S = 100001;
vector<int> Seive(S);
void seive()
{
    fill(Seive.begin(), Seive.end(), 0);
    Seive[0] = 0;
    Seive[1] = 0;
    for (long long i = 2; i <= S; i++)
    {
        if (Seive[i])
            continue;
        for (long long j = i * i; j <= S; j += i)
            Seive[j] = 1;
    }
}

int main()
{
    seive();
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        if (!Seive[i])
            cout << i << " ";
    cout << endl;
    return 0;
}