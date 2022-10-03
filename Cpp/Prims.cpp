#include <bits/stdc++.h>
using namespace std;

int primsMst(vector<vector<int>> adj)
{
    int n = adj.size();
    int key[n], res = 0;
    fill(key, key + n, INT_MAX);
    key[0] = 0;
    bool mset[n] = {false};

    for (int k = 0; k < n; k++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!mset[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mset[u] = true;
        res += key[u];

        for (int i = 0; i < n; i++)
        {
            if (!mset[i] && adj[u][i] != 0)
                key[i] = min(key[i], adj[u][i]);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> adj = {
        {0, 2, INT_MAX, 6, INT_MAX},
        {2, 0, 3, 8, 5},
        {INT_MAX, 3, 0, INT_MAX, 7},
        {6, 8, INT_MAX, 0, 9},
        {INT_MAX, 5, 7, 9, 0}};

    int n = adj.size();

    cout << primsMst(adj) << endl;
}