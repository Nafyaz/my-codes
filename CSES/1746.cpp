#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n, m;
ll x[100005];
ll dp[100005][102];

ll call(ll pos, ll last)
{
    if(pos == n)
        return 1;
    if(dp[pos][last] != -1)
        return dp[pos][last];
    
    if(x[pos])
    {
        if(abs(x[pos] - last) > 1)
            return dp[pos][last] = 0;
        else
            return dp[pos][last] = call(pos+1, x[pos]);
    }

    ll i, ret = 0;
    for(i = max(1LL, last-1); i <= min(m, last+1); i++)    
        ret = (ret + call(pos+1, i)) % mod;
    
    return dp[pos][last] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, ans;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> x[i];

    memset(dp, -1, sizeof dp);
    if(x[0])
    {
        cout << call(1, x[0]) << "\n";
        return 0;
    }

    ans = 0;
    for(i = 1; i <= m; i++)            
        ans = (ans + call(1, i)) % mod;
    
    cout << ans << "\n";
}