#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;

    ll ret = bigmod(a, p/2);
    ret = (ret * ret) % MOD;

    if(p&1)
        ret = (ret * a) % MOD;

    return ret;
}

ll getInv(ll a)
{
    return bigmod(a, MOD-2);
}

void solve(int caseno)
{
    ll n, i, ans;

    cin >> n;

    if(n%2)
    {
        cout << "0\n";
        return;
    }

    n /= 2;
    ans = 1;
    for(i = 1; i <= n; i++)
    {
        ans = (ans * (4*i - 2)) % MOD;
        ans = (ans * getInv(i+1)) % MOD;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}