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

unordered_set<int> adj[MAXN];
vector<pii> edges;

void solve(int caseno)
{
    int n, m, i, u, v, cur;
    ll ans, total;
    vector<int> small;
    unordered_set<int> large;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);

        edges.push_back({u, v});
    }

    for(i = 1; i <= n; i++)
    {
        if(adj[i].size()*adj[i].size() < 2*m)
            small.push_back(i);
        else
            large.insert(i);
    }

    ans = 0;
    for(auto s : small)
    {
        for(auto nxt1 : adj[s])
        {
            for(auto nxt2 : adj[nxt1])
            {
                if(adj[s].find(nxt2) != adj[s].end())
                    ans -= (adj[s].size() - 2)*(adj[s].size() - 3) / 2;
            }
        }
    }

    for(auto [bg, ed] : edges)
    {
        if(large.find(bg) != large.end() && large.find(ed) != large.end())
        {
            for(auto l : large)
            {
                if(adj[l].find(bg) != adj[l].end() && adj[l].find(ed) != adj[l].end())
                {
                    ans -= (adj[l].size() - 2)*(adj[l].size()-3);
                }
            }
        }
    }

    for(cur = 1; cur <= n; cur++)
    {
        total = adj[cur].size();

        for(auto nxt : adj[cur])
        {
            if(adj[nxt].size() >= 2)
                ans += (adj[nxt].size() - 1) * (total-1)*(total-2)*(total-3)/6;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
