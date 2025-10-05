#include <bits/stdc++.h>
using namespace std;

vector<int> grid[26][3000];

bool check(int ch, int r1, int r2)
{
    int c1 = 0, c2 = 0, cnt = 0;
    while (c1 < grid[ch][r1].size() && c2 < grid[ch][r2].size())
    {
        if (grid[ch][r1][c1] == grid[ch][r2][c2])
        {
            cnt++;
            c1++;
            c2++;
        }
        else if (grid[ch][r1][c1] < grid[ch][r2][c2])
            c1++;
        else
            c2++;

        if (cnt == 2)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    string s;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            grid[s[j] - 'A'][i].push_back(j);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < grid[2][i].size(); j++)
    //         cout << grid[2][i][j] << " ";
    //     cout << "\n";
    // }

    for (int ch = 0; ch < k; ch++)
    {
        bool gotYes = false;
        for (int r1 = 0; r1 < n && !gotYes; r1++)
        {
            for (int r2 = 0; r2 < r1 && !gotYes; r2++)
            {
                gotYes = check(ch, r1, r2);
            }
        }

        cout << (gotYes ? "YES\n" : "NO\n");
    }
}