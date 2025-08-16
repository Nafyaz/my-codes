#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 50004

vector<long long> adj[MAXN];
long long dp[MAXN][502], ans;

void dfs(long long node, long long par, long long k)
{
    dp[node][0] = 1;

    for (auto u : adj[node])
    {
        if (u == par)
            continue;

        dfs(u, node, k);

        for (int i = 1; i <= k; i++)
        {
            dp[node][i] += dp[u][i - 1];
        }
    }

    long long total = 0;
    for (auto u : adj[node])
    {
        if (u == par)
            continue;

        for (int i = 1; i < k; i++)
            total += dp[u][i - 1] * (dp[node][k - i] - dp[u][k - i - 1]);
    }

    ans += total / 2 + dp[node][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k, i;

    cin >> n >> k;

    for (i = 1; i < n; i++)
    {
        long long a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, k);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans << "\n";
}