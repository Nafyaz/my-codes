#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 998244353
#define maxN 200005

ll bOne[maxN];

void solve(ll caseno)
{
    ll n, m, i, p, ans, add;
    string a, b;

    cin >> n >> m;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(i = 0; i < m; i++)
        bOne[i+1] = bOne[i] + (b[i] == '1');

    ans = 0;
    p = 1;
    for(i = 0; i < min(m, n); i++)
    {
        if(a[i] == '1')
        {
            add = ((p * (bOne[m] - bOne[i])) % mod + mod) % mod;
            ans = (ans + add) % mod;
        }
        p = (p*2) % mod;
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