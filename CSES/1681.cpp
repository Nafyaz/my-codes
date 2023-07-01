#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll dp[MAXN];
vector<ll> adj[MAXN];

ll dfs(ll cur, ll p)
{
    if(dp[cur] != -1)
        return dp[cur];

    ll ret = 0;

    for(auto nxt : adj[cur])
    {
        if(nxt != p)        
            ret = (ret + dfs(nxt, cur)) % MOD;        
    }

    return dp[cur] = ret;
}

void solve(ll caseno)
{
    ll n, m, i, j, a, b;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    memset(dp, -1, sizeof dp);
    dp[1] = 1;

    cout << dfs(n, -1) << "\n";
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