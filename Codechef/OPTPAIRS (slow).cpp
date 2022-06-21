#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll g(ll a, ll b)
{
    return __gcd(a, b) + a*b/__gcd(a, b);
}

void solve(ll caseno)
{
    ll n, a, b, mn = INT_MAX, cnt = 0;

    // n = caseno;
    cin >> n;

    for(a = 1; a < n; a++)
    {
        b = n-a;
        // mn = min(mn, g(a, b));
        if(g(a, b) == n)
        {
            cout << a << " " << b << "\n";
            cnt++;
        }
    }

    if(mn != n)
        cout << n;
    // cout << cnt << "\n\n";
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