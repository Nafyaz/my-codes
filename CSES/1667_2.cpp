#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int dist[MAXN], parent[MAXN];
vector<int> adj[MAXN];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto u : adj[node])
        {
            if (dist[u] != -1)
                continue;

            dist[u] = dist[node] + 1;
            q.push(u);
            parent[u] = node;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dist, -1, sizeof dist);

    bfs(1);

    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n] + 1 << "\n";
    stack<int> stk;
    for (int node = n; node != 0; node = parent[node])
    {
        stk.push(node);
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}