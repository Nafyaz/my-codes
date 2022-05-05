#include<bits/stdc++.h>
using namespace std;
#define ll long long

string grid[1003];
ll column[1003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q, i, j, total = 0, x, y, ans, temp;

    cin >> n >> m >> q;

    for(i = 0; i < n; i++)
    {
        cin >> grid[i];

        for(j = 0; j < m; j++)
        {
            total += (grid[i][j] == '*');
            column[j] += (grid[i][j] == '*');
        }
    }

    ans = 0;
    temp = total;
    for(j = 0; j < m; j++)
    {
        ans += min(n, temp - column[j]);
        temp -= min(n, temp);
    }

    while(q--)
    {
        cin >> x >> y;

        if(grid[x][y] == '*')
        {
            grid[x][y] = '.';
            total--;
            column[y]--;

            
        }
        else
        {
            grid[x][y] = = '*';
            total ++;
            column[y] ++;
        }
    }
}