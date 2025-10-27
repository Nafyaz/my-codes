#include <bits/stdc++.h>
using namespace std;

#define MAXN 2503

int n, m;
int parent[MAXN];
long long dist[MAXN];
vector<pair<long long, int>> adj[MAXN];
vector<pair<long long, pair<int, int>>> edges;

void dijkstra(int source)
{
    for (int i = 1; i <= n; i++)
        dist[i] = LLONG_MAX;

    set<pair<long long, int>> st;
    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty())
    {
        int node = (*st.begin()).second;
        long long d = (*st.begin()).first;

        st.erase(st.begin());

        if (node == source)
            break;

        if (dist[node] < d)
            continue;

        for (auto [d2, node2] : adj[node])
        {
            if (dist[node2] > dist[node] + d2)
            {
                dist[node2] = dist[node] + d2;
                st.insert({dist[node2], node2});
                parent[node2] = node;
            }
        }
    }

    stack<int> stk;

    int node = source;
    stk.push(node);

    do
    {
        node = parent[node];
        stk.push(node);
    } while (node != source);

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        edges.push_back({c, {a, b}});
    }

    for (int i = 1; i <= n + 1; i++)
    {
        for (auto edge : edges)
        {
            long long c = edge.first;
            int a = edge.second.first;
            int b = edge.second.second;

            if (dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;

                if (i == n + 1)
                {
                    cout << "YES\n";
                    dijkstra(a);
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
}