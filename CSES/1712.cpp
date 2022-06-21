#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll bigmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 1%mod;
    if(b == 1)
        return a%mod;

    ll res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        return (a*res)%mod;
    return res;
}

void solve(ll caseno)
{
    ll a, b, c;

    cin >> a >> b >> c;

    ll p = bigmod(b, c, MOD-1);
    cout << bigmod(a, p, MOD) << "\n";
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