#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll bigmod(ll a, ll b)
{
    if(b == 0)
        return 1%MOD;
    if(b == 1)
        return a%MOD;

    ll res = bigmod(a, b>>1);
    res = (res*res)%MOD;
    if(b&1)
        return (a*res)%MOD;
    return res;
}

void solve(ll caseno)
{
    ll a, b;

    cin >> a >> b;

    if(a == 0 && b == 0)
        cout << "1\n";
    else
        cout << bigmod(a, b) << "\n";
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