#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

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

    dp[0] = 1;
    for(j = 1; j <= x; j++)
    {
        for(i = 1; i <= n; i++)
        {
            if(c[i] <= j)
                dp[j] = (dp[j] + dp[j-c[i]]) % mod;
        }
    }

    cout << dp[x];
}