#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector<int> adj[MAXN];
int dp[2][MAXN];

int dfs(int tookPar, int node, int par)
{
    if (dp[tookPar][node] != -1)
        return dp[tookPar][node];

    // cout << tookPar << " " << node << "\n";

    int total = 0;
    for (auto u : adj[node])
    {
        if (u == par)
            continue;

        total += dfs(0, u, node);
    }

    dp[tookPar][node] = total;

    if (tookPar == 0)
    {
        for (auto u : adj[node])
        {
            if (u == par)
                continue;

            dp[tookPar][node] = max(dp[tookPar][node], total - dfs(0, u, node) + dfs(1, u, node) + 1);
        }
    }

    return dp[tookPar][node];
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

    memset(dp, -1, sizeof dp);
    cout << dfs(0, 1, -1);
}