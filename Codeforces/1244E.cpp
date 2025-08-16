#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll a[MAXN], pref[MAXN];

void solve(ll caseno)
{
    ll n, k, i, ans, L, H, opL, opH;
    ll pos, low, high, mid;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    sort(a+1, a+n+1);

    for(i = 1; i <= n; i++)
        pref[i] = pref[i-1] + a[i];

    ans = INT_MAX;
    for(i = 1; i <= n; i++)
    {
        L = a[i];
        opL = L*i - pref[i];

        low = L;
        high = a[n];
        while(low <= high)
        {
            mid = (low + high) / 2;
            H = mid;

            pos = upper_bound(a+1, a+n+1, H) - a-1;
            opH = pref[n] - pref[pos] - H*(n-pos);

            if(opL + opH <= k)
            {
                ans = min(ans, H-L);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        H = a[i];
        opH = pref[n] - pref[i] - H*(n-i);

        low = a[1];
        high = H;
        while(low <= high)
        {
            mid = (low + high) / 2;
            L = mid;

            pos = lower_bound(a+1, a+n+1, L) - a-1;
            opL = L*pos - pref[pos];

            if(opL + opH <= k)
            {
                ans = min(ans, H-L);
                low = mid + 1;
            }
            else
                high = mid - 1;
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