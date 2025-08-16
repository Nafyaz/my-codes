#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define show(x) cout << #x << ": " << x << "; "

ll n, m, k;
ll dp[1003][5003];

ll call(ll pos, ll prev)
{
    // show(pos);
    // show(prev);
    // cout << "\n";

    if(dp[pos][prev] != -1)
        return dp[pos][prev];

    // show(dp[pos][prev]);
    // cout << "\n";

    if(pos == n)
        return dp[pos][prev] = 1;

    ll i, ret = 0;
    for(i = 1; i <= m; i++)
    {
        if(prev == 0)
            ret = (ret + call(pos+1, i)) % mod;
        else if(abs(prev - i) >= k)
            ret = (ret + call(pos+1, i)) % mod;
    }

    return dp[pos][prev] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    memset(dp, -1, sizeof dp);
    cout << call(0, 0);
}