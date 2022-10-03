#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int> &a)
{
    vector<int> len;
    for (auto &x : a)
    {
        auto it = lower_bound(len.begin(), len.end(), x);
        if (it == len.end())
            len.push_back(x);
        else
            *it = x;
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    vector<int> LIS_arr = LIS(arr);
    for (auto &x : LIS_arr)
        cout << x << " ";
    cout << endl;
}