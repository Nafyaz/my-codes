#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 998244353
#define MAXN 1000006

ll fact[MAXN];

ll getFact(ll n)
{
    if(n <= 1)
        return fact[n] = 1;

    if(fact[n] != 0)
        return fact[n];

    return fact[n] = (getFact(n-1) * n) % MOD;
}

ll bigmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a%MOD;

    ll res = bigmod(a, b>>1);
    res = (res*res)%MOD;
    if(b&1)
        return (a*res)%MOD;
    return res;
}

ll invmod(ll a)
{
    return bigmod(a, MOD-2);
}

ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;

    ll ret = getFact(n);
    ret = (ret * invmod(getFact(r))) % MOD;
    ret = (ret * invmod(getFact(n-r))) % MOD;
    return ret;
}

void solve(ll caseno)
{
    ll n, k, ans, sub;

    cin >> n;

    ans = getFact(n);

    for(k = 2; k < n; k++)
    {
        ans = (ans + getFact(n) - 1) % MOD;
        sub = (nCr(n, k) * getFact(n-k) - 1) % MOD;
        ans = ((ans - sub) % MOD + MOD) % MOD;
    }

    cout << ans << "\n";
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