#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

bool vis[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];

int dfs(int cur)
{
    if (vis[cur])
        return cur;

    vis[cur] = true;

    for (auto nxt : adj[cur])
    {
        if (nxt == parent[cur])
            continue;

        parent[nxt] = cur;
        int ret = dfs(nxt);
        if (ret != 0)
            return ret;
    }
    
    return 0;
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

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        int st = dfs(i);
        if (st != 0)
        {
            int node = st;
            stack<int> stk;
            stk.push(node);
            do {
                node = parent[node];
                stk.push(node);
            } while (node != st);

            cout << stk.size() << "\n";
            while (!stk.empty()) {
                cout << stk.top() << " ";
                stk.pop();
            }

            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}