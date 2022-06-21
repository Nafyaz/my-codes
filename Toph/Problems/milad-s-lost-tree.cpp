#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll sum[MAXN], val[MAXN];
vector<ll> adj[MAXN];

bool dfs(ll cur, ll p = -1)
{
    if(sum[cur] == -1)
    {
        val[cur] = 0;
        if(cur == 1)
            sum[cur] = 0;
        else
            sum[cur] = sum[p];
    }
    else
    {
        if(cur == 1)
            val[cur] = sum[cur];
        else
            val[cur] = sum[cur] - sum[p];
    }

    if(val[cur] < 0)
        return 0;

    for(auto nxt : adj[cur])
    {
        if(nxt != p)
        {
            if(!dfs(nxt, cur) || sum[nxt] < sum[cur])
                return 0;            
        }
    }

    return 1;
}

void solve(ll caseno)
{
    ll n, i, u, v, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> sum[i];
        adj[i].clear();
    }

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(!dfs(1))
        cout << "Case " << caseno << ": -1\n";
    else
    {
        ans = 0;
        for(i = 1; i <= n; i++)
            ans += val[i];
        cout << "Case " << caseno << ": " << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}