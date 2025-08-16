#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n;
vector<ll> adj[200005];
ll subSize[200005];

void dfs(ll node, ll p)
{
    subSize[node] = 1;
    for(auto u : adj[node])
    {
        if(u != p)
        {
            dfs(u, node);
            subSize[node] += subSize[u];
        }
    }
}

ll getAns(ll node, ll p)
{
    ll ret = 0, left, right;

    for(auto u : adj[node])
    {
        if(u == p)
            continue;

        left = subSize[u]*(subSize[u]-1)/2 + subSize[u];
        right = subSize[node]-subSize[u];

        ret = (ret + left * right) % mod;
        ret = (ret + getAns(u, node)) % mod;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, u, v, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            subSize[i] = 0;
        }

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        cout << getAns(1, -1);
    }
}
