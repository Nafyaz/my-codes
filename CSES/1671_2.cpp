#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector<pair<long long, int>> adj[MAXN];
long long dist[MAXN];

void djikstra(int source) {
    set<pair<long long, int>> st;

    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty()) {
        long long d = (*st.begin()).first;
        int node = (*st.begin()).second;

        st.erase(st.begin());

        if (d > dist[node])
            continue;

        for (auto [d2, node2] : adj[node]) {
            if (d+d2 < dist[node2]) {
                st.insert({d+d2, node2});
                dist[node2] = d+d2;
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
        dist[i] = LLONG_MAX;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    djikstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n";
}