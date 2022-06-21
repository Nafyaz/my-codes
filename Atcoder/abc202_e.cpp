#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll parent[maxN];
vector<ll> adj[maxN];
ll bg[maxN], ed[maxN], level[maxN];
vector<ll> bgInLevels[maxN];
ll Time;

void dfs(ll node, ll l)
{
    level[node] = l;
    bg[node] = ++Time;
    bgInLevels[l].push_back(Time);

    for(auto u : adj[node])    
        dfs(u, l+1);

    ed[node] = ++Time;
}

void solve(ll caseno)
{
    ll n, i, q, u, d;

    cin >> n;

    Time = 0;
    for(i = 1; i <= n; i++)
    {
        adj[i].clear();
        bgInLevels[i].clear();
    }

    for(i = 2; i <= n; i++)
    {
        cin >> parent[i];
        adj[parent[i]].push_back(i);
    }

    dfs(1, 0);

    cin >> q;

    while(q--)
    {
        cin >> u >> d;

        if(d < level[u])
            cout << "0\n";
        else
            cout << lower_bound(bgInLevels[d].begin(), bgInLevels[d].end(), ed[u]) - lower_bound(bgInLevels[d].begin(), bgInLevels[d].end(), bg[u]) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}