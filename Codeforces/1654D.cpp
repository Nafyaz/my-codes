#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mod 998244353

pair<ll, map<ll, ll>> amount[200005];
vector<pair<ll, pair<ll, ll>>> adj[200005];

ll lp[200005];
vector<ll> primes;
map<ll, ll> LCM;

void linSieve()
{
    ll i, j;

    for(i = 2; i < 200005; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            primes.push_back(i);
        }

        for(j = 0; j < primes.size() && primes[j] <= lp[i] && i*primes[j] < 200005; j++)
            lp[i*primes[j]] = primes[j];
    }
}

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    ll ret = bigmod(a, p/2);
    ret = (ret*ret)%mod;

    if(p&1)
        ret = (ret*a)%mod;

    return ret;
}

ll invmod(ll a)
{
    return bigmod(a, mod-2);
}

void dfs(ll s, ll p)
{
    ll x = amount[s].ff;
//    ll y = amount[s].ss;

//    cout << "In dfs of " << s << ": " << x << ", " << y << "\n";

    for(auto u : adj[s])
    {
        if(u.ff == p)
            continue;

        ll xNew = (x*u.ss.ff) % mod;
        ll yNew = u.ss.ss;

        amount[u.ff] = {xNew, yNew};

        dfs(u.ff, s);
    }
}

void findLCM(ll y)
{
    map<ll, ll> freq;

    while(y > 1)
    {
        freq[lp[y]]++;
        y /= lp[y];
    }

    for(auto u : freq)
        LCM[u.ff] = max(LCM[u.ff], u.ss);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    linSieve();

    ll t, n, i, j, k, x, y, g, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(k = 1; k < n; k++)
        {
            cin >> i >> j >> x >> y;

            g = __gcd(x, y);
            x /= g;
            y /= g;

            adj[i].push_back({j, {(y*invmod(x))%mod, x}});
            adj[j].push_back({i, {(x*invmod(y))%mod, y}});
        }

        cout << "The Graph:\n";
        for(i = 1; i <= n; i++)
        {
            cout << i << ": ";
            for(auto u : adj[i])
                cout << u.ff << ", (" << u.ss.ff << ", " << u.ss.ss << "); ";
            cout << "\n";
        }

        map<ll, ll> temp;
        amount[1] = {1, temp};
        dfs(1, -1);

        cout << "The Amounts:\n";
        for(i = 1; i <= n; i++)
            cout << i << ": " << amount[i].ff << ", " << amount[i].ss << "\n";

        ans = 0;
        for(i = 1; i <= n; i++)
            ans = (ans + amount[i].ff) % mod;

        LCM.clear();
        for(i = 1; i <= n; i++)
            findLCM(amount[i].ss);

        cout << "The LCM:\n";
        for(auto u : LCM)
            cout << u.ff << " " << u.ss << "; ";
        cout << "\n";

        for(auto u : LCM)
            ans = (ans * invmod(bigmod(u.ff, u.ss))) % mod;

        cout << ans << "\n";
    }
}
/*
3
4
3 2 3 4
1 2 4 3
1 4 2 4
*/
