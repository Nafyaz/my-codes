#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool call(ll a, ll b, ll x)
{
    if(x == a || x == b) 
        return 1;
    
    if(a == 0 || b < x)
        return 0;

    if(a <= x && b%a == x%a)
        return 1;

    if(call(b%a, a, x))
        return 1;

    return 0;
}

void solve()
{
    ll a, b, x;

    cin >> a >> b >> x;

    if(a > b)
        swap(a, b);

    cout << (call(a, b, x)? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
