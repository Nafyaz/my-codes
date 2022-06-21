#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    
    ll ret = bigmod(a, p/2);
    ret = (ret * ret) % mod;

    if(p&1)
        ret = (ret * a) % mod;

    return ret;
}

void solve(ll caseno)
{
    ll n, m, k;

    cin >> n >> m >> k;

    if(k == -1 && n%2 != m%2)
        cout << "0\n";
    else
        cout << bigmod(bigmod(2, n-1), m-1) << "\n";
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