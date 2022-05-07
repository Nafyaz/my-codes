#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j;

    cin >> n;

    dp[0] = 1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= 6; j++)
        {
            if(i >= j)
                dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }

    cout << dp[n];
}