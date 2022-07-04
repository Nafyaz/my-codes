#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n, l;
ll dp[102][2][3003];
ll a[102][2];

ll call(ll prevType, bool side, ll len)
{
    if(len == l)
        return dp[prevType][side][len] = 1;
    else if(len > l)
        return 0;

    if(dp[prevType][side][len] != -1)
        return dp[prevType][side][len];

    ll i, ret;

    ret = 0;
    for(i = 1; i <= n; i++)
    {
        if(i != prevType && a[i][0] == a[prevType][side^1])
            ret = (ret + call(i, 0, len+a[i][0])) % MOD;

        if(i != prevType && a[i][0] != a[i][1] && a[i][1] == a[prevType][side^1])
            ret = (ret + call(i, 1, len+a[i][1])) % MOD;
    }

    return dp[prevType][side][len] = ret;
}

void solve(ll caseno)
{
    ll i, ans;
    cin >> n >> l;

    for(i = 1; i <= n; i++)    
        cin >> a[i][0] >> a[i][1];
    
    memset(dp, -1, sizeof dp);
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        ans = (ans + call(i, 0, a[i][0])) % MOD;
        if(a[i][0] != a[i][1])
            ans = (ans + call(i, 1, a[i][1])) % MOD;
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