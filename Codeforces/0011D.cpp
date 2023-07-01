#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<ll> adj[20];
ll dp[20][1LL << 20];

ll dfs(ll cur, ll p, ll root, ll mask)
{
    if(dp[cur][mask] != -1)
        return dp[cur][mask];
    
    ll ret = 0;
    for(auto nxt : adj[cur])
    {
        if(nxt != p)
        {
            if((mask & (1LL << nxt)) == 0)        
                ret += dfs(nxt, cur, root, mask | (1LL << nxt));
            else if(nxt == root)
                ret ++;
        }
    }

    return dp[cur][mask] = ret;
}

void solve(ll caseno)
{
    ll n, m, i, a, b, ans, mask;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans = mask = 0;
    for(i = 1; i <= n; i++)
    {
        memset(dp, -1, sizeof dp);
        mask |= (1LL << i);

        ans += dfs(i, -1, i, mask);
    }

    cout << ans/2 << "\n";
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