#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 502

vector<ll> adj[MAXN];
ll cap[MAXN][MAXN];
bool vis[MAXN];
ll parent[MAXN];

ll bfs(ll s, ll t)
{
    memset(vis, 0, sizeof vis);

    ll cur, flow, new_flow;
    
    queue<pll> q;
    q.push({INT_MAX, s});
    vis[s] = 1;

    while(!q.empty())
    {
        flow = q.front().ff;
        cur = q.front().ss;
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(vis[nxt] == 0 && cap[cur][nxt])
            {
                parent[nxt] = cur;
                new_flow = min(flow, cap[cur][nxt]);
                
                if(nxt == t)
                    return new_flow;

                q.push({new_flow, nxt});
                vis[nxt] = 1;
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t)
{
    ll prev, cur;
    ll flow = 0, new_flow;

    while(new_flow = bfs(s, t))
    {
        // show(new_flow);
        // cout << "\n";
        flow += new_flow;

        for(cur = t; cur != s; cur = prev)
        {
            prev = parent[cur];

            // show(prev);
            // show(cur);
            // cout << "\n";

            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }

        // for(ll i = 1; i <= 4; i++)
        // {
        //     for(ll j = 1; j <= 4; j++)
        //         cout << cap[i][j] << " ";
        //     cout << "\n";
        // }
    }

    return flow;
}

void solve(ll caseno)
{
    ll n, m, i, a, b, c;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;

        cap[a][b] += c;
        // cap[b][a] += c;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << maxflow(1, n) << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
