#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

vector<pair<ll, ll>> edges[500005];
vector<pair<ll, ll>> adj[500005];
ll parent[500005], sz[500005];

ll dfs(ll node)
{
    sz[node] = 1;

    for(auto u : adj[node])
    {
        if(u != parent[node])
        {
            parent[u] = node;
            sz[node] += dfs(u);
        }
    }

    return sz[node];
}

void solve()
{
    ll n, u, v, x, i;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> u >> v >> x;

        edges[x].push_back({u, v});
        adj[u].push_back({x, v});
        adj[v].push_back({x, u});
    }

    dfs(1);

    for(i = 1; i <= n; i++)
    {
        for(auto &u : edges[i])
        {
            if(u.ss == parent[u.ff])
                swap(u.ff, u.ss);
        }
    }
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