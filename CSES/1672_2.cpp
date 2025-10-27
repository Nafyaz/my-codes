#include <bits/stdc++.h>
using namespace std;

#define MAXN 502

vector<pair<long long, int>> adj[MAXN];
long long dist[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, q;

    cin >> n >> m >> q;

    memset(dist, -1, sizeof dist);

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (dist[a][b] == -1 || dist[a][b] > c)
        {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] > 0 && dist[k][j] > 0 && (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
}