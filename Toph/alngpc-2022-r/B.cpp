#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
//typedef long long LL;
typedef unsigned long long uLL;
//typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const uLL MOD = 4294967291;
const uLL MAXN = 2000006;

uLL bigmod(uLL a, uLL p, uLL MOD)
{
    if(p == 0)
        return 1%MOD;
    if(p == 1)
        return a%MOD;

    uLL res = bigmod(a, p/2, MOD);
    res = (res*res)%MOD;
    if(p&1LL)
        return (a*res)%MOD;
    return res;
}

void solve(int caseno)
{
    uLL n, ans;

    cin >> n;

//    cout << bigmod(3, n, MOD) << " " << bigmod(2, n-1, MOD) << "\n";

    ans = ((bigmod(3, n, MOD) - 1) * bigmod(2, n-1, MOD)) % MOD;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

