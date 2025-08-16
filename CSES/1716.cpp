#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll fact[MAXN];

ll getFact(ll x)
{
    if(fact[x] != 0)
        return fact[x];
    if(x <= 1)
        return fact[x] = 1;
    
    return fact[x] = (getFact(x-1) * x) % MOD;
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

ll invmod(ll a, ll m)
{
    return bigmod(a, m-2, m);
}

void solve(ll caseno)
{
    ll n, m;

    cin >> n >> m;

    cout << (((getFact(n+m-1) * invmod(getFact(n-1), MOD)) % MOD) * invmod(getFact(m), MOD)) % MOD << "\n";
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