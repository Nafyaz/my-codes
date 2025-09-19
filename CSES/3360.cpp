#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

bitset<3000> grid[26][3000];

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
        for (int j = 0; j < s.size(); j++)
        {
            grid[s[j] - 'A'][i].set(j);
        }
    }

    for (int i = 0; i < k; i++)
    {
        bool gotYes = false;
        for (int j = 0; j < n && !gotYes; j++)
        {
            for (int k = 0; k < j && !gotYes; k++)
            {
                if ((grid[i][j] & grid[i][k]).count() >= 2)
                    gotYes = true;
            }
        }

        cout << (gotYes ? "YES\n" : "NO\n");
    }
}