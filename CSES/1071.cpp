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

void solve(int caseno)
{
    ll x, y, mx, mn, ans;

    cin >> y >> x;

    mx = max(x, y);
    mn = min(x, y);

    ans = (mx - 1) * (mx - 1);

    if(mx%2 == 0)
    {
        if(x == mx)
            ans += y;
        else
        {
            ans += mx;
            ans += (mx - mn);
        }
    }
    else
    {
        if(x == mx)
        {
            ans += mx;
            ans += (mx - mn);
        }
        else
            ans += x;
    }

    cout << ans << "\n";
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