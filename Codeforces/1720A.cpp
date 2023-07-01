#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    ll a, b, c, d, g, e, f, ans;

    cin >> a >> b >> c >> d;

    g = __gcd(a, b);
    a /= g;
    b /= g;

    g = __gcd(c, d);
    c /= g;
    d /= g;

    if(max(a, c) != 0)
        e = (a*c)/__gcd(a, c);
    f = (b*d)/__gcd(b, d);

//    g = __gcd(e, f);
//    e /= g;
//    f /= g;
//
//    show(a);
//    show(b);
//    show(c);
//    show(d);
//    cout << "\n";
//
//    show(e);
//    show(f);
//    cout << "\n";

    ans = 0;
    if(a != e)
        ans++;
    if(c != e)
        ans++;
    if(b != f)
        ans++;
    if(d != f)
        ans++;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

