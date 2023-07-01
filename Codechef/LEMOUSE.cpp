#include<bits/stdc++.h>
using namespace std;
#define ll long long

string grid[102];
ll dp[102][102][2], n, m;


bool isValid(ll row, ll col)
{
    if(row < 0 || row >= n || col < 0 || col >= m)
        return 0;
    else
        return 1;
}

ll call(ll row, ll col, ll dir)
{
    if(isValid(row, col) == 0)
        return INT_MAX;

    // if(row == 0 && col == 1 && dir == 1)
    //     cout << dp[0][1][1] << "\n";

    if(dp[row][col][dir] != -1)
        return dp[row][col][dir];

    if(row == 0 && col == 0)    
        return dp[row][col][dir] = (grid[0][0] == '1') + (grid[0][1] == '1') + (grid[1][0] == '1');;
    
    dp[row][col][dir] = INT_MAX;

    if(row > 0 && col > 0)
    {
        if(dir == 0)
        {
            dp[row][col][0] = min(dp[row][col][0], call(row-1, col, 0)) + (grid[row][col-1] == '1');
            dp[row][col][0] = min(dp[row][col][0], call(row-1, col, 1));
        }
        else
        {
            dp[row][col][1] = min(dp[row][col][1], call(row, col-1, 1) + (grid[row-1][col] == '1'));
            dp[row][col][1] = min(dp[row][col][1], call(row, col-1, 0));
        }
    }
    else if(row > 0 && dir == 0)    
        dp[row][col][0] = call(row-1, col, 0);
    else if(col > 0 && dir == 1)
        dp[row][col][1] = call(row, col-1, 1);

    dp[row][col][dir] += (grid[row][col+1] == '1') + (grid[row+1][col] == '1');
    // cout << "inCall: " << row << " " << col << " " << dir << "; " << dp[row][col][dir] << "\n";

    return dp[row][col][dir];
}

void solve()
{
    ll i, j;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        grid[i].push_back('0');
    }
    grid[n] = string(m+1, '0');

    memset(dp, -1, sizeof dp);
    // call(2, 1, 0);
    // call(2, 1, 1);
    cout << min(call(n-1, m-1, 0), call(n-1, m-1, 1)) << "\n";

    // for(i = 0; i <= n; i++)
    // {
    //     for(j = 0; j <= m; j++)
    //         cout << setw(4) << dp[i][j][0] << " ";
    //     cout << "\n";
    // }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}