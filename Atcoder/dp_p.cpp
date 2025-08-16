#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n;
vector<ll> adj[100005];
ll dp[100005][2];

ll dfs(ll node, ll parent, ll pColor)
{
    // cout << node << " " << pColor << "\n";
    if(dp[node][pColor] != -1)
        return dp[node][pColor];

    if(parent != -1 && adj[node].size() == 1)
    {
        if(pColor == 0)
            return dp[node][pColor] = 2;
        else
            return dp[node][pColor] = 1;
    }

    ll ret = 0, val1 = 1, val2 = 1;
    for(auto u : adj[node])
    {
        if(u == parent)
            continue;
        
        val1 = (val1 * dfs(u, node, 0)) % mod;
        if(pColor == 0)
            val2 = (val2 * dfs(u, node, 1)) % mod;
    }

    if(pColor == 0)
        ret = (val1 + val2) % mod;
    else
        ret = val1;

    return dp[node][pColor] = ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll i, a, b;

    cin >> n;
    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dp, -1, sizeof dp);
    cout << dfs(1, -1, 0) << "\n";

    // for(i = 1; i <= n; i++)
    // {
    //     cout << i << ": " << dp[i][0] << ", " << dp[i][1] << "\n";
    // }
}