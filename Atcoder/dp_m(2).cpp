#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[100005];
ll pref[100005], temp[100005];
ll a[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K, i, j;

    cin >> N >> K;

    for(i = 1; i <= N; i++)
        cin >> a[i];

    for(i = 0; i <= N; i++)
    {
        for(j = 0; j <= K; j++)
        {
            if(!i && !j)
                dp[j] = 1;
            else if(!j)
                dp[j] = 1;
            else if(!i)
                dp[j] = 0;
            else
                dp[j] = ((pref[j+1] - pref[max(0LL, j-a[i])]) % mod + mod) % mod;
     
            temp[j+1] = temp[j] + dp[j];
        }

        for(j = 0; j <= K; j++)
            pref[j+1] = temp[j+1];
    }

   cout << dp[K];
}
