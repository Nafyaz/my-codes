#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000006

int r, c;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
bool vis[MAXN];
int dist[MAXN];

bool isValid(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

int dfs(int x, int y)
{
    int node = x * c + y;

    if (vis[node])
        return 0;

    vis[node] = true;
    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int x2 = x + dirX[i];
        int y2 = y + dirY[i];
        int node2 = x2 * c + y2;

        // cout << x2 << " " << y2 << ": ";
        // cout << !isValid(x2, y2) << " " << vis[node2] << " " << (dist[node2] != -1) << "\n";

        if (!isValid(x2, y2) || dist[node2] != -1)
            continue;

        ret += dfs(x2, y2);
    }

    return ret;
}

void solve(int caseno)
{
    int s;
    cin >> r >> c >> s;
    string grid[r];

    queue<pair<int, int>> q;

    for (int x = 0; x < r; x++)
    {
        cin >> grid[x];

        for (int y = 0; y < c; y++)
        {
            int node = x * c + y;

            vis[node] = false;
            dist[node] = -1;

            if (x == 0 || x == r - 1 || y == 0 || y == c - 1)
            {
                dist[node] = s - 1;
                q.push({node, s - 1});
            }

            if (grid[x][y] == '#')
            {
                dist[node] = s;
                q.push({node, s});
            }
        }
    }

    while (!q.empty())
    {
        auto [node, d] = q.front();
        q.pop();

        int x = node / c;
        int y = node % c;

        if (dist[node] > d)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int x2 = x + dirX[i];
            int y2 = y + dirY[i];
            int node2 = x2 * c + y2;

            if (!isValid(x2, y2) || dist[node2] > d - 1)
                continue;

            dist[node2] = d - 1;
            q.push({node2, d - 1});
        }
    }

    // for (int x = 0; x < r; x++)
    // {
    //     for (int y = 0; y < c; y++)
    //         cout << vis[x * c + y] << "  ";
    //     cout << "\n";
    // }

    int ans = 0;

    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            int node = x * c + y;

            if (dist[node] == -1 && !vis[node])
            {
                ans = max(ans, dfs(x, y));
                // cout << "\n\n";
            }
        }
    }

    cout << "Case #" << caseno << ": " << ans << "\n";
}

int main()
{
    // freopen("B_input.txt", "r", stdin);
    // freopen("B_output.txt", "w", stdout);

    int T, caseno = 0;
    cin >> T;

    while (T--)
    {
        solve(++caseno);
    }
}