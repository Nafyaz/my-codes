#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll Fact[1000006];

ll bigmod(ll n, ll p)
{
    if(p == 0)
        return 1;
    
    ll ret = bigmod(n, p/2);
    ret = (ret * ret) % mod;

    if(p&1)
        ret = (ret * n) % mod;
    
    return ret;
}

ll invmod(ll n)
{
    return bigmod(n, mod - 2);
}

ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;

    ll ret = Fact[n];
    ret = (ret * invmod(Fact[r])) % mod;
    ret = (ret * invmod(Fact[n-r])) % mod;

    return ret;
}

ll nPr(ll n, ll r)
{
    if(n < r)
        return 0;
    
    ll ret = Fact[n];
    ret = (ret * invmod(Fact[n-r])) % mod;

    return ret;
}

ll dp[1003][1003];

ll call(ll n, ll k)
{
    if(dp[n][k] != -1)
        return dp[n][k];

    if(n == k)
        return dp[n][k] = 1;

    if(n < k || n == 0 || k == 0)
        return dp[n][k] = 0;

    // if(k == 1)
    //     return dp[n][k] = 1;

    ll ret = (call(n-1, k) * k + call(n-1, k-1)) % mod;

    return dp[n][k] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m, k, i, ans;

    Fact[0] = 1;
    for(i = 1; i < 1000006; i++)    
        Fact[i] = (Fact[i-1] * i) % mod;    

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> k;

        memset(dp, -1, sizeof dp);

        ans = 0;
        for(i = 1; i <= k; i++)
        {
            ans = (ans + (nPr(m, i)*(call(n, i))) ) % mod;
        }

        cout << ans << "\n";        
    }
}