#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

set<int> adj[102][3];

void solve(int caseno)
{
    int n, m, i, u, v, cur, ans;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[min(u, v)][1].insert(max(u, v));
    }

    for(cur = 1; cur <= n; cur++)
    {
        for(auto nxt1 : adj[cur][1])
        {
            for(auto nxt2 : adj[nxt1][1])
                adj[cur][2].insert(nxt2);
        }
    }

//    for(cur = 1; cur <= n; cur++)
//    {
//        show(cur);
//        for(auto nxt2 : adj[cur][2])
//            show(nxt2);
//        cout << "\n";
//    }

    ans = 0;
    for(cur = 1; cur <= n; cur++)
    {
        for(auto nxt1 : adj[cur][1])
        {
            for(auto nxt2 : adj[nxt1][1])
            {
                if(adj[cur][1].find(nxt2) != adj[cur][1].end())
                    ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
