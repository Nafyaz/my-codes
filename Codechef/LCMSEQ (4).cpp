#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll fact[MAXN], invFact[MAXN], Pow[MAXN];
ll mp2[MAXN];

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

ll invmod(ll a)
{
    return bigmod(a, MOD-2);
}

ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;

    ll ret = fact[n];
    ret = (ret * invFact[r]) % MOD;
    ret = (ret * invFact[n-r]) % MOD;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    Pow[0] = fact[0] = invFact[0] = 1;
    for(ll i = 1; i < MAXN; i++)
    {
        Pow[i] = (Pow[i-1] * 2) % MOD;
        fact[i] = (fact[i-1] * i) % MOD;
        invFact[i] = (invFact[i-1] * invmod(i)) % MOD;
    }

    cin >> T;

    while(T--)
    {
        int n, i, x, ans, val, cnt;
        map<int, int> mp;

        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++;
        }

        fill(mp2, mp2 + n + 1, 0);
        ans = 0;
        auto it = mp.begin();
        while(it != mp.end())
        {
            val = it->ff;
            cnt = it->ss;

            ans = ((ans + Pow[cnt] - cnt - 1) % MOD + MOD) % MOD;

            for(i = 1; i*i <= val; i++)
            {
                if(val%i == 0)
                {
                    if(i != 1 && i <= n)
                    {
                        ans = ((ans - nCr(cnt, i)) % MOD + MOD) % MOD;
                        mp2[i] += cnt;
                    }

                    if(i*i != val && val/i <= n)
                    {
                        ans = ((ans - nCr(cnt, val/i)) % MOD + MOD) % MOD;
                        mp2[val/i] += cnt;
                    }
                }
            }

            it++;
        }

        // cout << "mp:\n";
        // for(auto [a, b] : mp)
        //     cout << a << " " << b << "\n";
        // cout << "mp2:\n";
        // for(auto [a, b] : mp2)
        //     cout << a << " " << b << "\n";
        
        for(i = 2; i <= n; i++)
            ans = (ans + nCr(mp2[i], i)) % MOD;
        
        cout << ans << "\n";
    }
}