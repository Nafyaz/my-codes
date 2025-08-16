#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[402], pref[402], dp[402][402];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, st, ed, len;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
        dp[i][i] = 0;
    }

    for(len = 2; len <= n; len++)
    {
        for(st = 1; st + len - 1 <= n; st++)
        {
            ed = st + len - 1;
            dp[st][ed] = LLONG_MAX;
            for(i = st; i < ed; i++)            
                dp[st][ed] = min(dp[st][ed], pref[ed] - pref[st-1] + dp[st][i] + dp[i+1][ed]);            
        }
    }

    cout << dp[1][n];
}