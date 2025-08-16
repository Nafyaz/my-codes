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

LL a[MAXN];
vector<pLL> adj[MAXN];

LL dfs(LL node, LL p, LL mx)
{
    LL ret = 0;

    if(mx > a[node])
    {
        // show(node);
        // show(mx);
        // cout << "\n";

        ret = 1;
        mx = LLONG_MAX;
    }

    for(auto [d, nxt] : adj[node])
    {
        if(nxt == p)
            continue;

        if(mx != LLONG_MAX)
            ret += dfs(nxt, node, max(mx+d, 0LL));
        else
            ret += dfs(nxt, node, mx);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, p, c;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i < n; i++)
    {
        cin >> p >> c;

        adj[i+1].push_back({c, p});
        adj[p].push_back({c, i+1});
    }

    // for(i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for(auto u : adj[i])
    //     {
    //         cout << u.ff << " " << u.ss << "; ";
    //     }

    //     cout << "\n";
    // }

    cout << dfs(1, 0, 0) << "\n";
}