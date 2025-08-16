#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2003

ll n;
vector<pair<ll, pll>> edges;
vector<pll> adjL[MAXN];
ll adjM[MAXN][MAXN];
ll root[MAXN];
ll dist[MAXN];

ll Find(ll x)
{
    if(root[x] == x)
        return x;
    return root[x] = Find(root[x]);
}

void Union(ll x, ll y)
{
    x = Find(x);
    y = Find(y);

    root[max(x, y)] = min(x, y);
}

ll kruskal()
{
    ll i, ret = 0;
    for(i = 1; i <= n; i++)
        root[i] = i;

    sort(edges.begin(), edges.end());
    ll cnt = 0;
    for(auto [c, e] : edges)
    {
        auto [a, b] = e;

        if(Find(a) != Find(b))
        {
            Union(a, b);
            adjL[a].push_back({c, b});
            adjL[b].push_back({c, a});

            ret += c;
            cnt++;
            if(cnt == n-1)
                return ret;
        }
    }

    return -1;
}

void dfs(ll cur, ll p, ll d)
{
    dist[cur] = d;

    for(auto [w, nxt] : adjL[cur])
    {
        if(nxt != p)        
            dfs(nxt, cur, d + w);        
    }
}

void solve(ll caseno)
{
    ll i, j, lca;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> adjM[i][j];

            if(i != j && adjM[i][j] == 0 || i == j && adjM[i][j] != 0)
            {
                cout << "NO\n";
                return;
            }

            if(i != j)
                edges.push_back({adjM[i][j], {i, j}});
        }
    }

    kruskal();
    for(i = 1; i <= n; i++)
    {
        dfs(i, -1, 0);

        for(j = 1; j <= n; j++)
        {
            if(dist[j] != adjM[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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