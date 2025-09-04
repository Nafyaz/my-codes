#include <bits/stdc++.h>
using namespace std;

int n, m;
string grid[1003];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
char dir[4] = {'U', 'L', 'D', 'R'};

map<pair<int, int>, pair<char, pair<int, int>>> parent;

bool isValid(pair<int, int> cell)
{
    return cell.first >= 0 && cell.first < n && cell.second >= 0 && cell.second < m && grid[cell.first][cell.second] != '#';
}

void print(pair<int, int> cell)
{
    cout << "YES\n";

    string s = "";

    while (parent.find(cell) != parent.end())
    {
        s.push_back(parent[cell].first);
        cell = parent[cell].second;
    }

    cout << s.size() << "\n";
    reverse(s.begin(), s.end());

    cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                grid[i][j] = '#';
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> child = {cell.first + dirX[i], cell.second + dirY[i]};

            if (isValid(child))
            {
                parent[child] = {dir[i], cell};

                if (grid[child.first][child.second] == 'B')
                {
                    print(child);
                    return 0;
                }

                grid[child.first][child.second] = '#';
                q.push(child);
            }
        }
    }

    cout << "NO\n";
}