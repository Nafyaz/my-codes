#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector<int> adj[MAXN];

pair<int, int> dfs(int node, int par)
{
    pair<int, int> ret = {node, 0};

    for (auto u : adj[node])
    {
        if (u == par)
            continue;

        pair<int, int> p = dfs(u, node);
        if (p.second >= ret.second)
        {
            ret = p;
            ret.second++;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int, int> p = dfs(1, -1);

    cout << dfs(p.first, -1).second << "\n";
}