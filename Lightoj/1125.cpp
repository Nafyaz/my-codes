#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, d;
ll a[202];
ll dp[202][21][11];

ll call(ll pos, ll rem, ll m)
{
    // cout << pos << " " << rem << " " << m << endl;
    if(dp[pos][rem][m] != -1)
        return dp[pos][rem][m];

    if(m == 0)
    {
        if(rem == 0)
            return dp[pos][rem][m] = 1;
        else
            return dp[pos][rem][m] = 0;
    }

    if(pos == n)
        return dp[pos][rem][m] = 0;

    ll ret = 0;
    ret += call(pos+1, rem, m);
    ret += call(pos+1, ((rem + a[pos])%d + d)%d, m-1);

    return dp[pos][rem][m] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, q, i, m;

    cin >> T;

    while(T--)
    {
        cin >> n >> q;

        for(i = 0; i < n; i++)
            cin >> a[i];

        cout << "Case " << ++caseno << ":\n";
        while(q--)
        {
            cin >> d >> m;

            memset(dp, -1, sizeof dp);
            cout << call(0, 0, m) << "\n";
        }
    }
}