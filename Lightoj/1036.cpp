#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n;
ll Uranium[502][502], Radium[502][502];
ll prefUranium[502][502], prefRadium[502][502];
ll dp[502][502];

ll call(ll row, ll col)
{
    if(dp[row][col] != -1)
        return dp[row][col];
    
    if(row == 0 || col == 0)
        return dp[row][col] = 0;

    return dp[row][col] = max(call(row-1, col) + prefUranium[row][col], call(row, col-1) + prefRadium[row][col]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i, j;

    cin >> T;

    while(T--)
    {
        cin >> m >> n;

        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                cin >> Uranium[i][j];
                prefUranium[i][j] = prefUranium[i][j-1] + Uranium[i][j];
            }
        }

        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                cin >> Radium[i][j];
                prefRadium[i][j] = prefRadium[i-1][j] + Radium[i][j];
            }
        }

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(m, n) << "\n";
    }
}