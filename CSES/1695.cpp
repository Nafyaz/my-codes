#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 502

int n;
vector<int> adj[MAXN];
int cap[MAXN][MAXN], parent[MAXN];
bool vis[MAXN];

int bfs(int bg, int ed)
{
    memset(vis, 0, sizeof vis);

    int new_flow;

    queue<pii> q;
    q.push({INT_MAX, bg});
    vis[bg] = 1;

    while(!q.empty())
    {
        auto [flow, cur] = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(vis[nxt] == 0 && cap[cur][nxt])
            {
                parent[nxt] = cur;
                new_flow = min(flow, cap[cur][nxt]);

                if(nxt == ed)
                    return new_flow;

                q.push({new_flow, nxt});
                vis[nxt] = 1;
            }
        }
    }

    return 0;
}

int maxflow(int bg, int ed)
{
    int prev, cur;
    int flow = 0, new_flow;

    while(new_flow = bfs(bg, ed))
    {
        flow += new_flow;

        for(cur = ed; cur != bg; cur = prev)
        {
            prev = parent[cur];

            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
        }
    }

    return flow;
}

void solve(int caseno)
{
    int m, i, a, b, cur;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        cap[a][b] = 1;
        cap[b][a] = 1;
    }

    cout << maxflow(1, n) << "\n";
    for(cur = 1; cur <= n; cur++)
    {
        if(!vis[cur])
            continue;
        for(auto nxt : adj[cur])
        {
            if(!vis[nxt])
                cout << cur << " " << nxt << "\n";
        }
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