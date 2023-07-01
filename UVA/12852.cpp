#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, m, i, lcm = 1;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> m;

        lcm = (lcm * m) / __gcd(lcm, m);
    }

    cout << "Case " << caseno << ": " << 35*lcm << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}