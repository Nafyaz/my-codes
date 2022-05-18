#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
ll C[102][102], toll[102][102];
ll dp[102][102];

ll call(ll t, ll r)
{
    if(dp[t][r] != -1)
        return dp[t][r];

    if(t == n)
        return dp[t][r] = 0;

    ll i, ret = LLONG_MAX;
    for(i = 0; i < m; i++)    
        ret = min(ret, call(t+1, i) + C[r][i]);
    
    return dp[t][r] = ret + toll[r][t];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, D, i, j, k, ans;

    cin >> T;

    while(T--)
    {
        cin >> D >> n >> m;

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                cin >> toll[i][j];
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
                cin >> C[i][j];
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
            {
                for(k = 0; k < m; k++)
                    C[j][k] = min(C[j][k], C[j][i]+C[i][k]);
            }
        }

        memset(dp, -1, sizeof dp);
        ans = LLONG_MAX;
        for(i = 0; i < m; i++)
            ans = min(ans, call(0, i));

        cout << max(-1LL, D - ans) << "\n";
    }
}