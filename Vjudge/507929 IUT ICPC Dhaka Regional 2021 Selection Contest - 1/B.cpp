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

bool isPrime(ll p)
{
    ll i;

    for(i = 2; i*i <= p; i++)
    {
        if(p%i == 0)
            return 0;
    }

    return 1;
}

ll findPhi(ll n)
{
    ll i, cnt, ret = n, temp = n;
    for(i = 2; i*i <= n; i++)
    {
        for(cnt = 0; n % i == 0; cnt++)
            n /= i;

        if(cnt > 0)
            ret = ret / i * (i - 1);
    }

    if(n > 1)
        ret = ret / n * (n - 1);

    return ret;
}

void solve(int caseno)
{
    ll n, p, mul, nominator, denominator;

    cin >> n;

    mul = 1;
    for(p = 2;; p++)
    {
        if(isPrime(p))
        {
            if(mul > n/p || mul*p > n)
                break;

            mul *= p;
        }
    }

    denominator = mul;
    nominator = denominator - findPhi(denominator);

    cout << nominator/__gcd(nominator, denominator) << "/" << denominator/__gcd(nominator, denominator) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

