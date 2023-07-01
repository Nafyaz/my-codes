#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 998244353
#define MAXN 200005

ll Fact[MAXN], Inv[MAXN];

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%MOD;

    ll res = bigmod(a, p/2);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

ll invmod(ll a)
{
    return bigmod(a, MOD-2);
}

ll nPr(ll n, ll r)
{
    return (Fact[n] * Inv[n-r])%MOD;
}

void solve(int caseno)
{
    ll n, i, arr, ans, ones;

    cin >> n;

    ones = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> arr;
        ones += (arr == 1);
    }

    ans = 0;
    for(i = 1; i <= ones; i++)    
        ans = (ans + nPr(ones, i)*Fact[n-i+1]) % MOD;
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    Fact[0] = Inv[0] = 1;
    for(ll i = 1; i < MAXN; i++)
    {
        Fact[i] = (Fact[i-1]*i)%MOD;
        Inv[i] = (Inv[i-1]*invmod(i))%MOD;
    }

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}