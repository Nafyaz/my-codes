#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n;
ll Uranium[502][502], Radium[502][502];
ll dp[502][502][102][102];

ll call(ll row, ll col, ll u, ll r)
{
    if(dp[row][col][u][r] != -1)
        return dp[row][col][u][r];
    
    if(row == 0)
        return dp[row][col][u][r] = r;
    if(col == 0)
        return dp[row][col][u][r] = u;

    ll ret = 0;
    ret = max(ret, call(row-1, col, ))
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
                cin >> Uranium[i][j];
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                cin >> Radium[i][j];
        }

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(m, n) << "\n";
    }
}