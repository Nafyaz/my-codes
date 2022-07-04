#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll fact[MAXN];

ll bigmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    ll res = bigmod(a, b>>1);
    res = (res*res)%MOD;
    if(b&1)
        return (a*res)%MOD;
    return res;
}

ll getFact(ll x)
{
    if(x == 0)
        return fact[x] = 1;
    
    if(fact[x] != 0)
        return fact[x];

    return fact[x] = (getFact(x-1) * x) % MOD;
}

ll invmod(ll a)
{
    return bigmod(a, MOD-2);
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
    ll n, i, x, ans, total;
    unordered_map<ll, ll> mp;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }

    unordered_map<ll, vector<ll>> mp2;
    for(auto &[val, cnt] : mp)
    {
        for(i = 1; i*i <= val; i++)
        {
            if(val%i == 0)
            {
                if(i != 1 && i <= n)
                    mp2[i].push_back(cnt);

                if(i*i != val && val/i <= n)
                    mp2[val/i].push_back(cnt);
            }
        }

        // show(val);
        // show(cnt);
        // cout << "\n";
        // for(auto [divisor, v] : mp2)
        // {
        //     cout << divisor << ":\n";
        //     for(auto u : v)
        //         cout << u << " ";
        //     cout << "\n";
        // }
    }
    
    ans = 0;
    for(auto &[val, cnt] : mp)
        ans = ((ans + bigmod(2, cnt) - cnt - 1) % MOD + MOD) % MOD;

    for(auto &[divisor, v] : mp2)
    {
        total = 0;
        for(auto &u : v)
        {
            total += u;
            ans = ((ans - nCr(u, divisor)) % MOD + MOD) % MOD;        
        }
        
        ans = (ans + nCr(total, divisor)) % MOD;
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