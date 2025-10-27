#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector<pair<long long, int>> adj[MAXN][2];
vector<pair<pair<int, int>, long long>> edges;
long long dist[MAXN][2];

void dijkstra(int node, int type)
{
    set<pair<long long, int>> st;
    st.insert({0, node});
    dist[node][type] = 0;

    while (!st.empty())
    {
        long long d = (*st.begin()).first;
        int node = (*st.begin()).second;

        st.erase(st.begin());

        if (dist[node][type] < d)
            continue;

        for (auto [d2, node2] : adj[node][type])
        {
            if (dist[node2][type] > d + d2)
            {
                st.insert({d + d2, node2});
                dist[node2][type] = d + d2;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        dist[i][0] = LLONG_MAX;
        dist[i][1] = LLONG_MAX;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        adj[a][0].push_back({c, b});
        adj[b][1].push_back({c, a});
        edges.push_back({{a, b}, c});
    }

    dijkstra(1, 0);
    dijkstra(n, 1);

    long long ans = LLONG_MAX;
    for (auto [p, c] : edges)
    {
        int a = p.first;
        int b = p.second;

        if (dist[a][0] != LLONG_MAX && dist[b][1] != LLONG_MAX)
            ans = min(ans, dist[a][0] + c / 2 + dist[b][1]);
    }

    cout << ans << "\n";
}