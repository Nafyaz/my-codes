#include<bits/stdc++.h>
using namespace std;
#define ll long long

string grid[102];

void solve(ll caseno)
{
    ll r, c, i, j;

    cin >> r >> c;

    for(i = 0; i < r; i++)
        cin >> grid[i];

    string mn = "z", str;
    mn[0]++;

    for(i = 0; i < r; i++)
    {
        str = "";
        for(j = 0; j < c; j++)
        {
            if(grid[i][j] == 'X')
            {
                if(str.size() >= 2)
                    mn = min(mn, str);
                str = "";
            }
            else
                str.push_back(grid[i][j]);
        }

        if(str.size() >= 2)
            mn = min(mn, str);
    }

    for(j = 0; j < c; j++)
    {
        str = "";
        for(i = 0; i < r; i++)
        {
            if(grid[i][j] == 'X')
            {
                if(str.size() >= 2)
                    mn = min(mn, str);
                str = "";
            }
            else
                str.push_back(grid[i][j]);
        }

        if(str.size() >= 2)
            mn = min(mn, str);
    }

    cout << "Case " << caseno << ": " << mn << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}