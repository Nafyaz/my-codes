#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[402], pref[402];
ll dp[402][402];

ll call(ll st, ll ed)
{
    if(dp[st][ed] != -1)
        return dp[st][ed];

    if(st == ed)
        return dp[st][ed] = 0;

    ll i, ret = LLONG_MAX;
    for(i = st; i < ed; i++)
        ret = min(ret, call(st, i) + call(i+1, ed) + pref[ed] - pref[st-1]);

    return dp[st][ed] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << call(1, n);
}