#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define show(x) cout << #x << ": " << x << "; "

ll n, m, k;
ll dp[1003][5003];
ll cSum[1003][5003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    ll i, j, ans;

    for(j = 1; j <= m; j++)
    {
        dp[n][j] = 1;
        cSum[n][j] = cSum[n][j-1] + 1;
    }

    for(i = n-1; i >= 1; i--)
    {
        for(j = 1; j <= m; j++)
        {
            dp[i][j] = ((cSum[i+1][max(0LL, j-k)] + cSum[i+1][m] - cSum[i+1][min(m, j+k-1)])%mod + mod)%mod;
            if(k == 0)
                dp[i][j] = ((dp[i][j] - dp[i+1][j]) % mod + mod) % mod;
            cSum[i][j] = (cSum[i][j-1] + dp[i][j]) % mod;
        }
    }

    // cout << "dp:\n";
    // for(j = 0; j <= m; j++)
    // {
    //     for(i = 0; i <= n; i++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // cout << "cSum:\n";
    // for(j = 0; j <= m; j++)
    // {
    //     for(i = 0; i <= n; i++)
    //         cout << cSum[i][j] << " ";
    //     cout << "\n";
    // }

    cout << cSum[1][m];
}