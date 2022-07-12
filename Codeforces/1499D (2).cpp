#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 20000007

ll c, d, x;
ll leastFactor[MAXN], cntPrimes[MAXN];
vector<ll> primes;

void linSieve()
{
    ll i, j;
    for (i = 2; i < MAXN; ++i)
    {
        if (leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);
        }
        for (j = 0; j < (ll)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < MAXN; ++j)
        {
            leastFactor[i * primes[j]] = primes[j];
        }
    }
}

void countPrimes()
{
    ll i, j;

    cntPrimes[1] = 0;
    for(i = 2; i < MAXN; i++)
    {
        if(leastFactor[i] != leastFactor[i/leastFactor[i]])
            cntPrimes[i] = cntPrimes[i/leastFactor[i]] + 1;
        else
            cntPrimes[i] = cntPrimes[i/leastFactor[i]];
    }
}

ll calc(ll gcd)
{
    if((x + d*gcd) % c != 0)
        return 0;
    
    ll lcm = (x + d*gcd)/c;

    if(lcm % gcd != 0)
        return 0;

    ll rem = lcm / gcd;

    return (1LL << cntPrimes[rem]);
}

void solve(ll caseno)
{
    ll g_cd, i, ans;

    cin >> c >> d >> x;

    g_cd = __gcd(c, d);

    if(x%g_cd != 0)
    {
        cout << "0\n";
        return;
    }
    
    ans = 0;
    for(i = 1; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            ans += calc(i);
            if(i*i != x)
                ans += calc(x/i);
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    linSieve();
    countPrimes();

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}