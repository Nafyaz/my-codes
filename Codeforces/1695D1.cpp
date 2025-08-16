#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2003

vector<ll> adj[MAXN];
ll level[MAXN], mxCnt;

void dfs(ll cur, ll p = -1, ll l = 0)
{
    level[l]++;
    mxCnt = max(mxCnt, level[l]);

    for(auto nxt : adj[cur])
    {
        if(nxt != p)        
            dfs(nxt, cur, l+1);        
    }
}

void solve(ll caseno)
{
    ll n, i, x, y, ans;
    
    cin >> n;

    for(i = 1; i <= n; i++)
        adj[i].clear();

    for(i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    ans = n+1;
    for(i = 1; i <= n; i++)
    {
        fill(level, level+n, 0);
        mxCnt = 0;
        dfs(i);

        ans = min(ans, mxCnt);
    }

    cout << ans << "\n";
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