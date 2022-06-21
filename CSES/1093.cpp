#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n;
ll dp[502][62630];

ll call(ll pos, ll rem)
{
    if(pos == n+1)
        return dp[pos][rem] = (rem == 0);
    
    if(dp[pos][rem] != -1)
        return dp[pos][rem];

    ll ret = call(pos+1, rem);
    if(pos <= rem)
        ret = (ret + call(pos+1, rem - pos)) % MOD;

    return dp[pos][rem] = ret;
}

ll bigmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 1%mod;
    if(b == 1)
        return a%mod;

    ll res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        return (a*res)%mod;
    return res;
}

ll invmod(ll a, ll mod)
{
    return bigmod(a, mod-2, mod);
}


void solve(ll caseno)
{
    ll i;

    cin >> n;

    if((n*(n+1)/2) % 2)
    {
        cout << "0\n";
        return;
    }

    memset(dp, -1, sizeof(dp));
    cout << (call(1, n*(n+1)/4) * invmod(2, MOD)) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}