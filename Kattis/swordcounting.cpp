#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

vector<pLL> edges;
unordered_set<LL> adj[MAXN];

LL nCr(LL n, LL r)
{
    if(n < r)
        return 0;
    
    if(r == 0)
        return 1;
    
    if(r == 1)
        return n;
    
    if(r == 2)
        return n*(n-1)/2;
    
    if(r == 3)
        return n*(n-1)*(n-2)/6;

    return INT_MAX;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, i, j, u, v, ans, common;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;

        edges.push_back({u, v});

        adj[u].insert(v);
        adj[v].insert(u);
    }

    ans = 0;
    for(auto [a, b] : edges)
    {
        if(adj[a].size() > adj[b].size())
            swap(a, b);

        common = 0;
        for(auto nxt : adj[a])
        {
            if(adj[b].find(nxt) != adj[b].end())
                common++;
        }

        ans += nCr(adj[a].size() - 1 - common, 3) * nCr(common, 0) * nCr(adj[b].size() - 1, 1);
        ans += nCr(adj[a].size() - 1 - common, 2) * nCr(common, 1) * nCr(adj[b].size() - 2, 1);
        ans += nCr(adj[a].size() - 1 - common, 1) * nCr(common, 2) * nCr(adj[b].size() - 3, 1);
        ans += nCr(adj[a].size() - 1 - common, 0) * nCr(common, 3) * nCr(adj[b].size() - 4, 1);

        ans += nCr(adj[b].size() - 1 - common, 3) * nCr(common, 0) * nCr(adj[a].size() - 1, 1);
        ans += nCr(adj[b].size() - 1 - common, 2) * nCr(common, 1) * nCr(adj[a].size() - 2, 1);
        ans += nCr(adj[b].size() - 1 - common, 1) * nCr(common, 2) * nCr(adj[a].size() - 3, 1);
        ans += nCr(adj[b].size() - 1 - common, 0) * nCr(common, 3) * nCr(adj[a].size() - 4, 1);
    }

    cout << ans << "\n";
}