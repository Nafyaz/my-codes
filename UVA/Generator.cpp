#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

void solve(ll caseno)
{
    ll n = 5, m = 100, l, r, x;

    cout << n << " " << m << "\n";

    for(ll i = 0; i < n; i++)
    {
        l = rand()%20;
        r = rand()%20 + l;

        cout << l << " " << r << "\n";
    }

    for(ll i = 0; i < m; i++)
    {
        x = rand()%40;
        cout << x << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(0));
    ll T = 3, caseno = 0;

    cout << T << "\n";

    while(T--)
    {
        solve(++caseno);
    }
}