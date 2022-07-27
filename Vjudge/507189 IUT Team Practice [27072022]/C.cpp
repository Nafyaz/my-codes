#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

int cnt;
map<int, int> mp;
set<int> adj[MAXN], adjRev[MAXN];
bool vis[MAXN];
vector<int> order, component;

void dfs1(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (!vis[u])
            dfs1(u);
    }
    order.push_back (v);
}

void dfs2(int v)
{
    vis[v] = 1;
    component.push_back(v);
    for (auto u : adjRev[v])
    {
        if(!vis[u])
            dfs2(u);
    }
}

void solve(int caseno)
{
    int n, m, i, a, b;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        if(mp.find(a) == mp.end())
            mp[a] = ++cnt;
        if(mp.find(b) == mp.end())
            mp[b] = ++cnt;

        adj[mp[a]].insert(mp[b]);
        adjRev[mp[b]].insert(mp[a]);
    }

    for(i = 1; i <= cnt; i++)
    {
        if(!vis[i])
            dfs1(i);
    }

    memset(vis, 0, sizeof vis);
    for(i = 1; i <= cnt; i++)
    {
        int v = order[cnt - i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}