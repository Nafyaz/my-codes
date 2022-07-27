#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

ll n, m;

ll lessOrEqual(ll val)
{
    ll i, ret = 0;

    for(i = 1; i <= n; i++)
        ret += min(val/i, m);
    return ret;
}

void solve(int caseno)
{
    ll k;
    ll low, high, mid, ans;

    cin >> n >> m >> k;

    low = 1;
    high = n*m;
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(lessOrEqual(mid) < k)
            low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
