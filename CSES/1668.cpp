#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

vector<int> adj[MAXN];
int color[MAXN];

bool dfs(int cur, int col)
{
    color[cur] = col;

    for (auto nxt : adj[cur])
    {
        if (color[nxt] == col)
            return false;
        if (color[nxt] == 0)
        {
            if (!dfs(nxt, 3 - col))
                return false;
        }
    }

    return true;
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
        if (color[i] != 0)
            continue;

        if (!dfs(i, 1))
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << color[i] << " ";
    cout << "\n";
}

