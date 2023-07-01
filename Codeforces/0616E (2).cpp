#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

LL calc(LL x)
{
    x = x%MOD;

    return (x*(x+1)/2) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, i, x, sub, ans;

    cin >> n >> m;

    ans = 0;
    
    if(n < m)
    {
        ans = ((m-n)%MOD * (n%MOD)) % MOD;
        m = n;
    }
    ans += (n%MOD) * (m%MOD);
    ans %= MOD;

    for(i = 1; i <= m; i++)
    {
        x = n/(n/i);
        x = min(x, m);

        sub = ((calc(x) - calc(i-1))%MOD + MOD) % MOD;
        sub *= ((n/i)%MOD);
        sub %= MOD;

        ans = ((ans - sub)%MOD + MOD) % MOD;

        i = x;
    }

    cout << ans << "\n";
}