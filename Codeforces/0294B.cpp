#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n;
ll t[102], w[102];
ll dp[102][202][202];

ll call(ll pos, ll T, ll W)
{
    if(W >= 202)
        return INT_MAX;
    if(pos == n)
    {
        if(T >= W)
            return T;
        else
            return INT_MAX;
    }

    if(dp[pos][T][W] != -1)
        return dp[pos][T][W];

    return dp[pos][T][W] = min(call(pos+1, T+t[pos], W), call(pos+1, T, W+w[pos]));
}

void solve(ll caseno)
{
    ll i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> t[i] >> w[i];

    memset(dp, -1, sizeof dp);
    cout << call(0, 0, 0) << "\n";
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