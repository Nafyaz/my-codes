#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool flag[MAXN];
vector<ll> primes;

void sieve()
{
    ll i, j;

    flag[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < MAXN; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < MAXN; j += 2*i)
                flag[j] = 0;
        }
    }

    primes.push_back(2);
    for(i = 3; i < MAXN; i += 2)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

ll NOD(ll n)
{
    ll i, c, ret = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        for(c = 0; n % primes[i] == 0; c++)
            n /= primes[i];
        ret *= (c+1);
    }

    if(n > 1)
        ret = ret << 1;

    return ret;
}

void solve(int caseno)
{
    int i, mx, mxnod = 0, nod;
    for(i = 1; i <= 510510; i++)
    {
        nod = NOD(i);

        if(nod > mxnod)
        {
            mxnod = nod;
            mx = i;
        }
    }

    cout << mx << " " << mxnod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}