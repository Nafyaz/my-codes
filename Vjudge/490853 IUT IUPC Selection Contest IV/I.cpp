#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[5003], b[5003];
ll pref[5003];
ll dp[5003][5003];

ll call(ll st, ll ed)
{
    if(dp[st][ed] != -1)
        return dp[st][ed];

    if(st == ed)
        return dp[st][ed] = 1;

    ll ret = 1, i;

    for(i = st; i+1 <= ed; i++)
    {
        if(pref[i] - pref[st-1] >= 0 && pref[ed] - pref[i] >= 0)
            ret = max(ret, 1 + call(i+1, ed));
    }

    return dp[st][ed] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];
        for(i = 1; i <= n; i++)
            cin >> b[i];

        for(i = 1; i <= n; i++)
            pref[i] = pref[i-1] + a[i]-b[i];

        if(pref[n] < 0)
        {
            cout << "-1\n";
            continue;
        }

        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << call(1, n) << "\n";
    }
}
