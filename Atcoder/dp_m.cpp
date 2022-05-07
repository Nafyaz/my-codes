#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[102][100005];
ll pref[102][100005];
ll a[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K, i, j, k;

    cin >> N >> K;

    for(i = 1; i <= N; i++)
        cin >> a[i];

    for(i = 0; i <= N; i++)
    {
        for(j = 0; j <= K; j++)
        {
            if(!i && !j)
                dp[i][j] = 1;
            else if(!j)
                dp[i][j] = 1;
            else if(!i)
                dp[i][j] = 0;
            else
                dp[i][j] = ((pref[i-1][j+1] - pref[i-1][max(0LL, j-a[i])]) % mod + mod) % mod;
     
            pref[i][j+1] = pref[i][j] + dp[i][j];
        }
    }

    // cout << "dp:\n";
    // for(i = 0; i <= N; i++)
    // {
    //     for(j = 0; j <= K; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    // cout << "pref:\n";
    // for(i = 0; i <= N; i++)
    // {
    //     for(j = 0; j <= K+1; j++)
    //         cout << pref[i][j] << " ";
    //     cout << "\n";
    // }

   cout << dp[N][K];
}
