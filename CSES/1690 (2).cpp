#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<ll> rev[21];
ll dp[21];

ll dfs(ll cur, ll p)
{
    if(dp[cur] != -1)
        return dp[cur];

    ll ret = 0;
    for(auto nxt : rev[cur])
    {
        if(nxt != p && (mask & (1LL << nxt)))        
            ret = (ret + dfs(nxt, cur, mask ^ (1LL << cur))) % MOD;        
    }

    return dp[cur][mask] = ret;
}

void solve(ll caseno)
{
    ll n, m, a, b, i;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        rev[b-1].push_back(a-1);
    }

    memset(dp, -1, sizeof dp);
    dp[0] = 1;

    cout << dfs(n-1, -1) << "\n";
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