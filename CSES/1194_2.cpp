#include <bits/stdc++.h>
using namespace std;

int n, m;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
string dirLabel = "ULDR";
string grid[1003];
int monsterDist[1003][1003], aDist[1003][1003];
int aPar[1003][1003];

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

void Print(int x, int y)
{
    string ans;
    while (aPar[x][y] != -1)
    {
        int d = aPar[x][y];
        ans.push_back(dirLabel[d]);

        x -= dirX[d];
        y -= dirY[d];
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    queue<pair<pair<int, int>, int>> mq, aq;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < m; j++)
        {
            monsterDist[i][j] = INT_MAX;
            aDist[i][j] = INT_MAX;
            aPar[i][j] = -1;

            if (grid[i][j] == 'M')
            {
                mq.push({{i, j}, 0});
                monsterDist[i][j] = 0;
            }

            if (grid[i][j] == 'A')
            {
                aq.push({{i, j}, 0});
                aDist[i][j] = 0;
            }
        }
    }

    while (!mq.empty())
    {
        int x = mq.front().first.first, y = mq.front().first.second;
        int d = mq.front().second;

        mq.pop();

        if (d > monsterDist[x][y])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int x2 = x + dirX[i];
            int y2 = y + dirY[i];
            int d2 = d + 1;

            if (isValid(x2, y2) && d2 < monsterDist[x2][y2])
            {
                mq.push({{x2, y2}, d2});
                monsterDist[x2][y2] = d2;
            }
        }
    }

    while (!aq.empty())
    {
        int x = aq.front().first.first, y = aq.front().first.second;
        int d = aq.front().second;

        aq.pop();

        if (d > aDist[x][y])
            continue;

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            cout << "YES\n";
            Print(x, y);
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int x2 = x + dirX[i], y2 = y + dirY[i];
            int d2 = d + 1;

            if (isValid(x2, y2) && d2 < monsterDist[x2][y2] && d2 < aDist[x2][y2])
            {
                aq.push({{x2, y2}, d2});
                aDist[x2][y2] = d2;
                aPar[x2][y2] = i;
            }
        }
    }

    cout << "NO\n";
}