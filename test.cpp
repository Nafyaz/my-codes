#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

pll a[10];

void solve(ll caseno)
{
    for(ll i = 0; i < 10; i++)
    {
        a[i].ff = i;
        a[i].ss = 2*i;
    }

    for(auto [x, y] : a)
        cout << x << " " << y << "\n";
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
