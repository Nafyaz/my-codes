#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll D[MAXN];
ll getDerange(ll n)
{
    if(n == 1)
        return D[1] = 0;
    if(n == 2)
        return D[2] = 1;
    if(D[n] != 0)
        return D[n];

    return D[n] = ((n-1) * (getDerange(n-1) + getDerange(n-2))) % MOD;
}

void solve(ll caseno)
{
    ll n;

    cin >> n;

    cout << getDerange(n) << "\n";
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