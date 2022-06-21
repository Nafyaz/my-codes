#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 300005

ll parent[maxN];
vector<ll> adj[maxN], children[maxN];
ll ans[maxN];

void dfs1(ll node, ll p)
{
    parent[node] = p;

    for(auto u : adj[node])
    {
        if(u != p)
        {
            children[node].push_back(u);
            dfs1(u, node);
        }
    }
}

ll dfs2(ll node)
{
    if(ans[node] != -1)
        return ans[node];


    if(children[node].empty())
        return ans[node] = 1;
    else if(children[node].size() == 1)
        return ans[node] = 2;
    else
        return ans[node] = min(2+dfs2(children[node][0]), 2+dfs2(children[node][1]));
}

void solve(ll caseno)
{
    ll n, i, u, v;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        adj[i].clear();
        children[i].clear();
        parent[i] = 0;
        ans[i] = -1;
    }

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);

    cout << n - dfs2(1) << "\n";

    // for(i = 1; i <= n; i++)
    // {
    //     show(i);
    //     show(ans[i]);
    //     for(auto u : children[i])
    //         cout << u << ", ";
    //     cout << "\n";
    // }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}