#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n, a[25][25];
ll dp[3000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j, mask;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> a[i][j];
    }

    dp[0] = 1;
    for(mask = 0; mask < (1LL << n); mask++)
    {
        i = __builtin_popcount(mask);
        for(j = 0; j < n; j++)
        {
            if(a[i][j] && (mask & (1LL << j)) == 0)
            {
                dp[mask | (1LL << j)] = (dp[mask | (1LL << j)] + dp[mask]) % mod;
            }
        }
    }

    cout << dp[(1LL << n) - 1];
}