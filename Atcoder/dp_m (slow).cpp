#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[102][100005];
ll a[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K, i, j, k;

    cin >> N >> K;

    for(i = 1; i <= N; i++)
        cin >> a[i];

    dp[0][0] = 1;
    for(i = 1; i <= N; i++)
    {
        dp[i][0] = 1;
        for(j = 1; j <= K; j++)
        {
            for(k = 0; k <= j; k++)
            {
                if(k <= a[i])
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
            }
        }
    }

   cout << dp[N][K];
}
