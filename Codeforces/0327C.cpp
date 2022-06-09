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
    ret = (ret*ret) % mod;

    if(p&1)
        ret = (ret*a) % mod;

    return ret;
}

ll invmod(ll a)
{
    return bigmod(a, mod-2);
}

void solve(ll caseno)
{
    string a;
    ll i, n, k, ans, temp;

    cin >> a >> k;
    n = a.size();

    ans = 0;
    for(i = 0; i < a.size(); i++)
    {
        if(a[i] == '0' || a[i] == '5')
        {
            temp = ((bigmod(2, n*k) - 1) * invmod(bigmod(2, n) - 1)) % mod;
            temp = (bigmod(2, i) * temp) % mod;
            ans = (ans + temp) % mod;
        }
    }

    cout << ans << "\n";
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