#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c[102];
ll dp[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, i, j;

    cin >> n >> x;

    for(i = 1; i <= n; i++)    
        cin >> c[i];
    
    memset(dp, -1, sizeof dp);
    for(i = 0; i <= n; i++)
    {
        dp[0] = 0;
        for(j = 1; j <= x; j++)
        {
            if(c[i] <= j && dp[j - c[i]] != -1)
            {
                if(dp[j] == -1)
                    dp[j] = dp[j - c[i]] + 1;
                else
                    dp[j] = min(dp[j], dp[j - c[i]] + 1);
            }
        }
    }

    cout << dp[x];
}