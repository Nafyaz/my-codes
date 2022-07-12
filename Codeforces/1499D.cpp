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

int c, d, x;
int leastFactor[MAXN];
vector<int> primes;

void linSieve()
{
    int i, j;
    for (i = 2; i < MAXN; ++i)
    {
        if (leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);
        }
        for (j = 0; j < (int)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < MAXN; ++j)
        {
            leastFactor[i * primes[j]] = primes[j];
        }
    }
}

ll calc(ll gcd)
{
    if((x + d*gcd) % c != 0)
        return 0;
    
    ll lcm = (x + d*gcd)/c;

    if(lcm % gcd != 0)
        return 0;

    ll rem = lcm / gcd, lp, cnt;

    // show(gcd);
    // show(lcm);
    // show(rem);
    cnt = 0;
    while(rem > 1)
    {
        lp = leastFactor[rem];
        if(rem%lp == 0)
        {
            cnt++;
            while(rem%lp == 0)
                rem /= lp;
        }
    }

    // show(rem);
    // show(cnt);
    // cout << "\n";

    return (1LL << cnt);
}

void solve(int caseno)
{
    int g_cd, i, ans;

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

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}