#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ss second
#define ff first

int n;
vector<int> dist[5003];
vector<pii> adj[5003];

void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1].push_back(0);
    pq.push({0, 1});

    while(!pq.empty())
    {
        auto [dis, node] = pq.top();
        pq.pop();

        sort(dist[node].begin(), dist[node].end());
        dist[node].resize(unique(dist[node].begin(), dist[node].end()) - dist[node].begin());
        while(dist[node].size() > 2)
            dist[node].pop_back();

        if(dist[node].size() == 2 && dis > dist[node].back())
            continue;

        if(node == n && dist[node].size() == 2 && dis == dist[node][1])
            break;

        for(auto [d, nxt] : adj[node])
        {
            dist[nxt].push_back(dis+d);
            pq.push({dis+d, nxt});
        }
    }
}

void solve(int caseno)
{
    int r;
    int u, v, w;

    cin >> n >> r;
    
    for(int i = 1; i <= n; i++)
    {
        dist[i].clear();
        adj[i].clear();
    }

    for(int i = 1; i <= r; i++)
    {
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dijkstra();

    cout << "Case " << caseno << ": " << dist[n].back() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}