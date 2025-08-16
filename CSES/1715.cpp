#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll fact[MAXN];
ll getFact(ll i)
{
    if(fact[i] != 0)
        return fact[i];
    if(i <= 1)
        return fact[i] = 1;

    return fact[i] = (getFact(i-1) * i)% MOD;
}

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

ll invmod(ll a, ll m)  //only if m is prime and gcd(a, m) = 1
{
    return bigmod(a, m-2, m);
}

void solve(ll caseno)
{
    ll n, i, ans = 1;
    string s;
    map<char, ll> mp;

    cin >> s;
    n = s.size();

    for(i = 0; i < n; i++)
        mp[s[i]] ++;
    
    for(auto u : mp)    
        ans = (ans * getFact(u.ss)) % MOD;
    
    ans = (getFact(n) * invmod(ans, MOD)) % MOD;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}