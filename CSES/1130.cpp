#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

vector<int> adj[MAXN];
int dp[MAXN][2];

int dfs(int v, int willTake, int par)
{
    if (dp[v][willTake] != -1)
        return dp[v][willTake];

    int total = 0;
    for (auto u : adj[v])
    {
        if (u == par)
            continue;

        total += dfs(u, 1, v);
    }
        

    if (!willTake)
        return dp[v][willTake] = total;

    int mx = 0;
    for (auto u : adj[v])
    {
        if (u == par)
            continue;

        mx = max(mx, total - dfs(u, 1, v) + dfs(u, 0, v) + 1);
    }
        

    return dp[v][willTake] = mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, b;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // for(i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto u : adj[i])
    //         cout << u << ", ";
    //     cout << "\n";
    // }
    
    memset(dp, -1, sizeof dp);
    cout << dfs(1, 1, -1) << "\n";
}