#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[102], pref[102];
ll dp[102][102];

ll call(ll st, ll ed)
{
    if(st > ed)
        return dp[st][ed] = 0;
    if(st == ed)
        return dp[st][ed] = a[st];
    
    if(dp[st][ed] != -1)
        return dp[st][ed];

    ll i, mine, diffAfter, mxDiff = INT_MIN;

    for(i = st; i <= ed; i++)
    {
        mine = pref[i] - pref[st-1];
        diffAfter = call(i+1, ed);
        mxDiff = max(mxDiff, mine - diffAfter);

        mine = pref[ed] - pref[i-1];
        diffAfter = call(st, i-1);
        mxDiff = max(mxDiff, mine - diffAfter);
    }

    return dp[st][ed] = mxDiff;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            pref[i] = pref[i-1] + a[i];
        }

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(1, n) << "\n";
    }
}