#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, a, b, i, bit, x, y, z;

    cin >> n >> a >> b;

    x = 0;
    for(i = n-1, bit = (1LL << (n-1)); i >= 0; i--, bit /= 2)
    {
        if((a^bit) * (b^bit) > a*b)
        {
            x += bit;
            a ^= bit;
            b ^= bit;
        }
    }

    cout << x << "\n";
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