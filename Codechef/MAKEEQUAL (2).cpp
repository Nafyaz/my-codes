#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

bool call(ll bit, ll a, ll b, ll c)
{
    // show(bit);
    // show(a);
    // show(b);
    // show(c);
    // cout << "\n";

    if(bit > (1LL << 12))
        return 0;

    if(a == b && b == c)
        return 1;
    
    if(call(bit*2, a+bit, b, c))
        return 1;
    if(call(bit*2, a, b+bit, c))
        return 1;
    if(call(bit*2, a, b, c+bit))
        return 1;
    
    return 0;
}

void solve(ll caseno)
{
    ll a, b, c;

    cin >> a >> b >> c;

    cout << (call(1, a, b, c)? "YES\n" : "NO\n");
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