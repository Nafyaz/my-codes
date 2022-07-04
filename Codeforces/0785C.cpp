#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll MUL(ll a, ll b)
{
    ll ret = 0;

    while(b)
    {
        if(a > 3e18)
            return LLONG_MAX;
        if(b&1)
            ret += a;
        if(ret > 3e18)
            return LLONG_MAX;

        a = a*2;
        b /= 2;
    }

    return ret;
}

void solve(ll caseno)
{
    ll n, m, low, high, mid, ans;

    cin >> n >> m;

    if(m >= n)
    {
        cout << n << "\n";
        return;
    }

    low = m;
    high = n;
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(2*n < MUL(mid-m-1, mid-m) || n - (mid-m-1)*(mid-m)/2 - mid <= 0)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
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