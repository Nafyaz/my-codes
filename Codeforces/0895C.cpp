#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll n;
ll freq[71];
vector<ll> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int dp[71][(1LL << 19) + 2];

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%MOD;

    ll res = bigmod(a, p/2);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

ll convert(ll x)
{
    ll i, cnt, ret = 0;

    for(i = 0; i < primes.size(); i++)
    {
        for(cnt = 0; x%primes[i] == 0; cnt++)
            x /= primes[i];

        if(cnt&1)
            ret += (1LL << i);
    }

    return ret;
}

void solve(ll caseno)
{
    ll i, j, a, conv, mx;

    cin >> n;

    mx = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        freq[a]++;

        mx = max(mx, a);
    }

    dp[0][0] = 1;
    for(i = 1; i <= mx; i++)
    {
        conv = convert(i);
        for(j = 0; j <= (1LL << 19); j++)
        {
            dp[i][j] = dp[i-1][j];
            if(freq[i])
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j^conv]*bigmod(2, freq[i]-1)) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j]*(bigmod(2, freq[i]-1) - 1)) % MOD;
            }
        }
    }

    // for(i = 0; i <= mx; i++)
    // {
    //     for(j = 0; j <= 2; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    
    cout << dp[mx][0] - 1 << "\n";
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