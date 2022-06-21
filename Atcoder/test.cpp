#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
// #define mod 1000000007
#define maxN 200005

ll bigmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 1%mod;
    if(b == 1)
        return a%mod;

    ll res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        return (a*res)%mod;
    return res;
}

bool isPrime2(ll n)
{
    vector<ll> checkerPrimes = {2, 3, 5, 7};
    if(binary_search(checkerPrimes.begin(), checkerPrimes.end(), n) == 1)
        return 1;

    vector<ll> carmichael = {561,1105,1729,2465,2821,6601,8911,10585,15841,
					29341,41041,46657,52633,62745,63973,75361,101101,
					115921,126217,162401,172081,188461,252601,278545,
					294409,314821,334153,340561,399001,410041,449065,
					488881,512461};

    if(binary_search(carmichael.begin(), carmichael.end(), n) == 1)
        return 0;

    for(auto cp : checkerPrimes)
    {
        if(bigmod(cp, n, n) != cp%n)
            return 0;
    }

    return 1;
}

bool isPrime(ll n)
{
    ll i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

void solve(ll caseno)
{
    ll i;

    // cout << isPrime(2) << " " << isPrime(3) << " " << isPrime(4) << " " << isPrime(5) << "\n";
    // cout << isPrime2(2) << " " << isPrime2(3) << " " << isPrime2(4) << " " << isPrime2(5) << "\n";

    for(i = 2; i <= 1000006; i++)
    {
        if(isPrime(i) != isPrime2(i))
        {
            cout << i;
            break;
        }
    }
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