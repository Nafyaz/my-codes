#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mod 1000000007

bool vis[100005];
vector<pair<ll, ll>> adj[100005];

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    
    ll ret = bigmod(a, p/2);
    ret = (ret*ret) % mod;

    if(p&1)
        ret = (ret*a)%mod;

    return ret;
}

ll dfs(ll node, ll parent)
{
    ll ret = 1;
    vis[node] = 1;

    for(auto u : adj[node])
    {
        if(u.ff == 0 && u.ss != parent)
            ret += dfs(u.ss, node);
    }

    return ret;
}

void solve()
{
    ll i, n, k, u, v, x, sz, ans;

    cin >> n >> k;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v >> x;
        adj[u].push_back({x, v});
        adj[v].push_back({x, u});
    }

    ans = bigmod(n, k);

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            sz = dfs(i, -1);
            ans = ((ans - bigmod(sz, k))%mod + mod)%mod;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}