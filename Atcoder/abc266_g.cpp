#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 998244353
#define MAXN 3000006

LL Fact[MAXN];

LL bigmod(LL a, LL p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%MOD;

    LL res = bigmod(a, p/2);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

LL invmod(LL a)
{
    return bigmod(a, MOD-2);
}

LL nCr(LL n, LL r)
{
    LL ret = Fact[n];

    ret = (ret * invmod(Fact[r])) % MOD;
    ret = (ret * invmod(Fact[n-r])) % MOD;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL R, G, B, K, i;
    LL ans;

    Fact[0] = 1;
    for(i = 1; i < MAXN; i++)
        Fact[i] = (Fact[i-1] * i) % MOD;

    cin >> R >> G >> B >> K;

    ans = Fact[K + R-K + B];
    ans = (ans * invmod(Fact[K])) % MOD;
    ans = (ans * invmod(Fact[R-K])) % MOD;
    ans = (ans * invmod(Fact[B])) % MOD;
    ans = (ans * nCr(K + B + G - K, G-K)) % MOD;

    cout << ans << "\n";
}