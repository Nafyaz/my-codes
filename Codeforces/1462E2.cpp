#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll fact[MAXN], arr[MAXN];

ll bigmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    ll res = bigmod(a, b>>1);
    res = (res*res) % MOD;
    if(b&1)
        return (a*res) % MOD;
    return res;
}

ll invmod(ll a)
{
    return bigmod(a, MOD-2);
}

ll getFact(ll n)
{
    if(fact[n] != 0)
        return fact[n];
    if(n <= 1)
        return fact[n] = 1;

    return fact[n] = (getFact(n-1) * n) % MOD;
}

ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;
    ll ret = getFact(n);
    ret = (ret * invmod(getFact(r))) % MOD;
    ret = (ret * invmod(getFact(n-r))) % MOD;

    return ret;
}

void solve(ll caseno)
{
    ll n, m, k, i, pos, ans;

    cin >> n >> m >> k;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    ans = 0;
    for(i = 0; i < n; i++)
    {
        pos = upper_bound(arr, arr+n, arr[i] + k) - arr;
        ans = (ans + nCr(pos - i - 1, m-1)) % MOD; 
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}