#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 998244353
#define MAXN 2000006

ll Fact[102];
ll n, arr[102];
ll freq[102], Inv[102];
ll dp[102][102][102];

ll bigmod(ll x, ll p)
{
    if(p == 0)
        return 1;

    ll ret = bigmod(x, p/2);
    ret = (ret * ret) % MOD;

    if(p&1)
        ret = (ret * x) % MOD;

    return ret;
}

ll inv(ll x)
{
    return bigmod(x, MOD-2);
}

ll nCr(ll n, ll r)
{
    return (((Fact[n] * Inv[r]) % MOD) * Inv[n-r]) % MOD;
}

ll calc(ll pos, ll taken, ll sz, ll req)
{
    if(pos == sz)
        return (req == 0) && (taken == sz);

    if(dp[pos][taken][req] != -1)
        return dp[pos][taken][req];

    ll ret = 0;
    for(ll i = 0; i <= freq[pos] && taken + i <= sz; i++)
        ret = (ret + nCr(freq[pos], i) * calc(pos+1, taken+i, sz, (req + pos*i)%sz)) % MOD;

    return dp[pos][taken][req] = ret;
}

void solve(int caseno)
{
    ll n, i, sz, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    ans = n;
    for(sz = 2; sz <= n; sz++)
    {
        for(i = 0; i < sz; i++)
            freq[i] = 0;

        for(i = 0; i < n; i++)
            freq[arr[i]%sz]++;

        memset(dp, -1, sizeof dp);
        ans = (ans + calc(0, 0, sz, 0)) % MOD;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    Fact[0] = 1;
    Inv[0] = 1;
    for(ll i = 1; i < 102; i++)
    {
        Fact[i] = (Fact[i-1] * i) % MOD;
        Inv[i] = inv(Fact[i]);
    }

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
