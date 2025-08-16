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

ll degree[MAXN];
ll fact[MAXN];

ll bigmod(ll n, ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return n;
    
    ll ret = bigmod(n, p/2);
    ret = (ret * ret) % MOD;

    if(p&1)
        ret = (ret * n) % MOD;
    
    return ret;
}

ll invmod(ll n)
{
    return bigmod(n, MOD-2);
}

ll nCr(ll n, ll r)
{
    ll ret = fact[n];
    ret = (ret * invmod(fact[r])) % MOD;
    ret = (ret * invmod(fact[n-r])) % MOD;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k, odd, even, i, ans, u, v;

    fact[0] = 1;
    for(i = 1; i < MAXN; i++)
        fact[i] = (fact[i-1] * i) % MOD;

    cin >> n >> m >> k;

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;

        degree[u]++;
        degree[v]++;
    }

    odd = 0;
    for(i = 1; i <= n; i++)
    {
        if(degree[i]&1)
            odd++;
    }

    even = n - odd;

    ans = 0;
    for(i = 0; i <= odd && i <= k; i += 2)    
    {
        if(k-i <= even)
            ans = (ans + nCr(odd, i)*nCr(even, k-i)) % MOD;
    }
    
    cout << ans << "\n";
}