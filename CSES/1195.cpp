#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector<pair<long long, int>> adj[MAXN];
long long dist[MAXN][2];

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

        adj[a].push_back({c, b});
    }

    set<pair<pair<long long, int>, int>> st;
    st.insert({{0, 1}, 0});
    dist[1][0] = 0;

    while (!st.empty())
    {
        long long d = (*st.begin()).first.first;
        int node = (*st.begin()).first.second;
        int type = (*st.begin()).second;

        st.erase(st.begin());

        if (dist[node][type] < d)
            continue;

        for (auto [d2, node2] : adj[node])
        {
            if (type == 0)
            {
                if (dist[node2][0] > d + d2)
                {
                    st.insert({{d + d2, node2}, 0});
                    dist[node2][0] = d + d2;
                }

                if (dist[node2][1] > d + d2 / 2)
                {
                    st.insert({{d + d2 / 2, node2}, 1});
                    dist[node2][1] = d + d2 / 2;
                }
            }
            else
            {
                if (dist[node2][1] > d + d2)
                {
                    st.insert({{d + d2, node2}, 1});
                    dist[node2][1] = d + d2;
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";
}