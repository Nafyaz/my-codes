#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 998244353
#define MAXN 200005

ll E[MAXN], a[MAXN];
ll suffE[MAXN];

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1%MOD;
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

void solve(int caseno)
{
    int n, i;

    cin >> n;

    for(i = 1; i < n; i++)
        cin >> a[i];

    for(i = n-1; i >= 1; i--)
    {
        E[i] = ((a[i]+1 + suffE[i+1] - suffE[i+a[i]+1])*invmod(a[i])) % MOD;
        E[i] = (E[i] + MOD) % MOD;
        suffE[i] = (suffE[i+1] + E[i]) % MOD;
    }

    cout << E[1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

