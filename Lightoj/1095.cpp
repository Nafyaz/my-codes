#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n, m, fact[1003], inv[1003];

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
    return bigmod(n, mod-2);
}

ll nCr(ll n, ll r)
{
    ll ret = fact[n];
    ret = (ret * invmod(fact[r])) % mod;
    ret = (ret * invmod(fact[n-r])) % mod;

    return ret;
}

ll Derange(ll n)
{
    ll ret = 0, add;

    for(ll i = 0; i <= n; i++)
    {
        add = (fact[n] * inv[i]) % mod;

        ret += ((i&1)? -add : add);
        ret = (ret%mod + mod) % mod;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i, j, k, ans, add;

    fact[0] = 1;
    inv[0] = invmod(1);

    for(i = 1; i < 1003; i++)
    {
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = invmod(fact[i]);
    }

    // cout << Derange(1);

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> k;

        ans = 0;

        for(i = 0; i <= n-m; i++)
        {
            add = (nCr(n-m, i) * Derange(n-k-i)) % mod;
            ans = (ans + add) % mod;
            // cout << ans << "\n";
        }

        ans = (ans * nCr(m, k)) % mod;

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}