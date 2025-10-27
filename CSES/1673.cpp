#include <bits/stdc++.h>
using namespace std;

#define MAXN 2503

long long dist[MAXN];
vector<pair<pair<int, int>, long long>> edges;
vector<int> adj[MAXN], revAdj[MAXN];
bool reachableFrom1[MAXN], canReachN[MAXN];

void dfs(int node)
{
    reachableFrom1[node] = true;
    for (auto node2 : adj[node])
    {
        if (!reachableFrom1[node2])
            dfs(node2);
    }
}

void dfs2(int node)
{
    canReachN[node] = true;
    for (auto node2 : revAdj[node])
    {
        if (!canReachN[node2])
            dfs2(node2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i] = LLONG_MIN;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        edges.push_back({{a, b}, c});
        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }

    dfs(1);
    dfs2(n);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto j : adj[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto j : revAdj[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }

    // for (int i = 1; i <= n; i++)
    //     cout << i << ": " << reachableFrom1[i] << " " << canReachN[i] << "\n";

    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (auto edge : edges)
        {
            int a = edge.first.first;
            int b = edge.first.second;
            long long c = edge.second;

            if (dist[a] != LLONG_MIN && dist[b] < dist[a] + c)
                dist[b] = dist[a] + c;
        }
    }

    for (auto edge : edges)
    {
        int a = edge.first.first;
        int b = edge.first.second;
        long long c = edge.second;

        if (dist[b] < dist[a] + c)
        {
            dist[b] = dist[a] + c;
            if (reachableFrom1[b] && canReachN[b])
            {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << dist[n] << "\n";
}