#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 8003

ll n;
ll s[MAXN], pref[MAXN];
ll dp[MAXN][3003];

ll call(ll pos, ll guards)
{
    if(pos > n)
        return 0;

    if(n - pos + 1 <= guards)
        return dp[pos][guards] = pref[n] - pref[pos-1];

    if(guards == 1)
        return dp[pos][guards] = (pref[n] - pref[pos-1]) * (n - pos + 1);

    if(dp[pos][guards] != -1)
        return dp[pos][guards];

    ll low = pos, high = n, mid1, mid2, v1, v2, cnt1, cnt2;
    ll ret = LLONG_MAX;
    while(low <= high)
    {
        mid1 = (2*low + high) / 3;
        cnt1 = mid1 - pos + 1;

        mid2 = (low + 2*high) / 3;
        cnt2 = mid2 - pos + 1;

        v1 = (pref[mid1] - pref[pos-1]) * cnt1 + call(mid1 + 1, guards-1);
        v2 = (pref[mid2] - pref[pos-1]) * cnt2 + call(mid2 + 1, guards-1);

        ret = min(ret, v1);
        ret = min(ret, v2);

        if(v1 < v2)
        {
            if(high != mid2 - 1)
                high = mid2 - 1;
            else
                high = mid2;
        }        
        else
        {
            if(low != mid1 + 1)
                low = mid1 + 1;
            else
                low = mid1;
        }
    }

    return dp[pos][guards] = ret;
}

void solve(ll caseno)
{
    ll g, i;

    cin >> n >> g;

    for(i = 1; i <= n; i++)
    {
        cin >> s[i];
        pref[i] = pref[i-1] + s[i];
    }

    memset(dp, -1, sizeof dp);
    cout << call(1, g) << "\n";

    // for(i = 0; i <= n; i++)
    // {
    //     for(ll j = 0; j <= g; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
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