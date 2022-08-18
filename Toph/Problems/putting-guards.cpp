#include<bits/stdc++.h>
using namespace std;
#define ll long long

string grid[25];

void solve(ll caseno)
{
    ll r, c, i, j, ans;

    cin >> r >> c;

    for(i = 0; i < r; i++)    
        cin >> grid[i];
    
    ans = (grid[0][0] == '1') + (grid[r-1][0] == '1') + (grid[0][c-1] == '1') + (grid[r-1][c-1] == '1');

    // cout << ans << "\n";

    for(j = 1; j < c; j++)        
    {
        ans += (grid[0][j-1] != grid[0][j]);
        ans += (grid[r-1][j-1] != grid[r-1][j]);
    }
    for(i = 1; i < r; i++)
    {
        ans += (grid[i-1][0] != grid[i][0]);
        ans += (grid[i-1][c-1] != grid[i][c-1]);
    }

    for(i = 1; i < r; i++)
    {
        for(j = 1; j < c; j++)
        {
            if(grid[i-1][j-1] == '0' && grid[i-1][j] == '0' && grid[i][j-1] == '0' && grid[i][j] == '1')
                ans++;
            if(grid[i-1][j-1] == '0' && grid[i-1][j] == '0' && grid[i][j-1] == '1' && grid[i][j] == '0')
                ans++;
            if(grid[i-1][j-1] == '0' && grid[i-1][j] == '1' && grid[i][j-1] == '0' && grid[i][j] == '0')
                ans++;
            if(grid[i-1][j-1] == '0' && grid[i-1][j] == '1' && grid[i][j-1] == '1' && grid[i][j] == '0')
                ans++;
            if(grid[i-1][j-1] == '0' && grid[i-1][j] == '1' && grid[i][j-1] == '1' && grid[i][j] == '1')
                ans++;
            if(grid[i-1][j-1] == '1' && grid[i-1][j] == '0' && grid[i][j-1] == '0' && grid[i][j] == '0')
                ans++;
            if(grid[i-1][j-1] == '1' && grid[i-1][j] == '0' && grid[i][j-1] == '0' && grid[i][j] == '1')
                ans++;
            if(grid[i-1][j-1] == '1' && grid[i-1][j] == '0' && grid[i][j-1] == '1' && grid[i][j] == '1')
                ans++;
            if(grid[i-1][j-1] == '1' && grid[i-1][j] == '1' && grid[i][j-1] == '0' && grid[i][j] == '1')
                ans++;
            if(grid[i-1][j-1] == '1' && grid[i-1][j] == '1' && grid[i][j-1] == '1' && grid[i][j] == '0')
                ans++;
        }
    }

    cout << "Case " << caseno << ": " << ans << "\n";
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