#include <bits/stdc++.h>
using namespace std;

vector<int> grid[26][3000];
int lastSeen[9000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    char s[3003];
    scanf("%d %d\n", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < n; j++)
            grid[s[j] - 'A'][i].push_back(j);
    }

    memset(lastSeen, -1, sizeof lastSeen);

    for (int ch = 0; ch < k; ch++)
    {
        bool gotYes = false;

        for (int r = 0; r < n && !gotYes; r++)
        {
            if (grid[ch][r].size() < 2)
                continue;

            for (int c1 = 0; c1 < grid[ch][r].size() && !gotYes; c1++)
            {
                for (int c2 = 0; c2 < c1 && !gotYes; c2++)
                {
                    int c = grid[ch][r][c1] * n + grid[ch][r][c2];
                    if (lastSeen[c] == ch)
                        gotYes = true;

                    lastSeen[c] = ch;
                }
            }
        }

        if (gotYes)
            printf("YES\n");
        else
            printf("NO\n");
    }
}