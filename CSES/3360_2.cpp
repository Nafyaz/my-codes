#include <bits/stdc++.h>
using namespace std;

unsigned long long grid[26][3000][47];

void Set(string s, int idx)
{
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'A';
        grid[c][idx][i / 64] |= (1ULL << (i % 64));
    }
}

bool And_PopCount(int idx, int i, int j)
{
    int cnt = 0;
    for (int k = 0; k < 47; k++)
    {
        cnt += __builtin_popcount(grid[idx][i][k] & grid[idx][j][k]);

        if (cnt >= 2)
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
        Set(s, i);
    }

    for (int i = 0; i < k; i++)
    {
        bool gotYes = false;
        for (int j = 0; j < n && !gotYes; j++)
        {
            for (int k = 0; k < j && !gotYes; k++)
            {
                gotYes = And_PopCount(i, j, k);
            }
        }

        cout << (gotYes ? "YES\n" : "NO\n");
    }
}