#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll calc(ll x)
{
    ll i, ret = 0;
    for(i = 2; i*i <= x; i++)
    {
        while(x % i == 0)
        {
            ret += i;
            x /= i;
        }
    }

    if(x > 1)
        ret += x;

    return ret;
}

void solve(ll caseno)
{
    ll n, q, a, b, gcd;

    cin >> n >> q;

    while(q--)
    {
        cin >> a >> b;

        gcd = __gcd(a, b);

        cout << calc(a/gcd) + calc(b/gcd) << "\n";
    }
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