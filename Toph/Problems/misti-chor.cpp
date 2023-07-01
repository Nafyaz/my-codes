#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

pll patil[MAXN];
ll ans[MAXN];

void solve(ll caseno)
{
    ll n, m, i, j, low, high, diff;

    cin >> n >> m;

    low = high = 0;
    for(i = 0; i < m; i++)
    {
        cin >> patil[i].ff >> patil[i].ss;
        low += patil[i].ff;
        high += patil[i].ss;

        ans[i] = patil[i].ff;
    }

    if(low > n || high < n)
    {
        cout << "-1\n";
        return;
    }

    n -= low;
    for(i = 0; i < m; i++)
    {
        diff = min(n, patil[i].ss - patil[i].ff);
        n -= diff;

        cout << ans[i] + diff << " ";
    }
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