#include <bits/stdc++.h>
using namespace std;

#define INF int(1e7)

int findset(int i, int parent[])
{
    if (parent[i] == -1)
        return i;
    return findset(parent[i], parent);
}

void unionset(int x, int y, int parent[])
{
    int s1 = findset(x, parent);
    int s2 = findset(y, parent);
    if (s1 > s2)
        swap(s1, s2);
    if (s1 != s2)
        parent[s2] = s1;
}

int kruskal(vector<vector<int>> cost, vector<vector<int>> t, int n)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pq.push({cost[i][j], {i, j}});
        }
    }

    int i = 0, minCost = 0;
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1;
    while (i < n - 1 && !pq.empty())
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int u = p.second.first, v = p.second.second;
        int j = findset(u, parent), k = findset(v, parent);
        if (j != k)
        {
            t[i][0] = u, t[i][1] = v;
            i++;
            minCost += p.first;
            unionset(j, k, parent);
        }
    }

    return minCost;
}

int main()
{
    int n = 5;
    vector<vector<int>> cost = {{INF, 2, INF, 6, INF},
                                {2, INF, 3, 8, 5},
                                {INF, 3, INF, INF, 7},
                                {6, 8, INF, INF, 9},
                                {INF, 5, 7, 9, INF}};
    vector<vector<int>> t(n - 1, vector<int>(2));
    cout << kruskal(cost, t, n);
    return 0;
}