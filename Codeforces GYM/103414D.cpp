#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<ll> adj[MAXN];
ll a[MAXN];
ll ans[MAXN];

void djikstra(ll node, ll d)
{
    ll cur, nd;
    multiset<pll> ms;

    nd = (d > a[node] ? d : d/2);
    ms.insert({nd, node});
    ans[node] = nd;

    while(!ms.empty())
    {
        ll d = (*ms.begin()).ff;
        ll cur = (*ms.begin()).ss;
        
        ms.erase(ms.begin());

        if(d < ans[cur])
            continue;

        for(auto nxt : adj[cur])
        {
            ll nd = (d > a[nxt] ? d : d/2);
            if(ans[nxt] == -1 || ans[nxt] < nd)
            {
                ms.insert({nd, nxt});
                ans[nxt] = nd;
            }
        }
    }
}

void solve(ll caseno)
{
    ll n, m, i, u, v, x;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> x;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    memset(ans, -1, sizeof ans);
    djikstra(1, x);

    cout << ans[n] << "\n";
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