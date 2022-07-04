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
    ll n, m, low, high, mid, ans;

    cin >> n >> m;

    if(m >= n)
    {
        cout << n << "\n";
        return;
    }

    low = 0;
    high = 2e9;
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(2*n < (mid-1)*(mid) || n - (mid-1)*mid/2 <= m+mid)
        {
            ans = m+mid;
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