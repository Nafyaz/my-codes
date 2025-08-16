#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
string grid[102];
ll dp[102][102][2];

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
    
    dp[0][0][0] = (grid[0][0] == '1');
    dp[0][0][1] = (grid[0][0] == '1');

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(i > 0 && j > 0)
            {
                dp[i][j][0] = INT_MAX;
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + (grid[i][j-1] == '1'));
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1]);

                dp[i][j][1] = INT_MAX;
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0]);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + (grid[i-1][j] == '1'));
            }
            else if(i > 0)            
            {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = INT_MAX;
            }
            else if(j > 0)
            {
                dp[i][j][0] = INT_MAX;
                dp[i][j][1] = dp[i][j-1][1];
            }

            dp[i][j][0] += (grid[i+1][j] == '1') + (grid[i][j+1] == '1');
            dp[i][j][1] += (grid[i+1][j] == '1') + (grid[i][j+1] == '1');;
        }
    }

    cout << min(dp[n-1][m-1][0], dp[n-1][m-1][1]) << "\n";
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