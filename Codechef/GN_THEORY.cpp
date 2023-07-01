#include<bits/stdc++.h>
using namespace std;
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

    for(i = 2; i < MAXN; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

void solve(ll caseno)
{
    ll n, q, u, v, i, p, cnt1, cnt2, ans;

    cin >> n >> q;

    while(q--)
    {
        cin >> u >> v;

        ans = 0;
        for(i = 0; i < primes.size(); i++)
        {
            p = primes[i];
            if(p*p > u && p*p > v)
                break;             

            for(cnt1 = 0; u%p == 0; cnt1++)
                u /= p;
            for(cnt2 = 0; v%p == 0; cnt2++)
                v /= p;

            ans += abs(cnt1 - cnt2) * p;
        }

        if(u != v)
        {
            if(u == 1)
                ans += v;
            else if(v == 1)
                ans += u;
            else
                ans += u + v;
        }

        cout << ans << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}