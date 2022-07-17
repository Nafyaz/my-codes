#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll L[MAXN], A[MAXN], B[MAXN], R[MAXN];
vector<ll> adj[MAXN];
ll parent[MAXN];
ll dp[MAXN][2];

void dfs(ll cur, ll p)
{
    parent[cur] = p;

    for(auto nxt : adj[cur])
    {
        if(nxt != p)
            dfs(nxt, cur);
    }
}

ll call(ll cur, bool willChange)
{
    // show(cur);
    // show(willChange);
    // cout << "\n";

    if(dp[cur][willChange] != -1)
        return dp[cur][willChange];

    ll ret = 0, add;
    for(auto nxt : adj[cur])
    {
        if(nxt != parent[cur])
        {
            add = LLONG_MAX;

            if(willChange)            
                add = min(add, call(nxt, 0) + abs(B[cur] - A[nxt]));
            else
            {
                add = min(add, call(nxt, 1) + abs(B[nxt] - A[cur]));
                add = min(add, call(nxt, 0) + abs(A[cur] - A[nxt]));
            }

            ret += add;
        }
    }

    return dp[cur][willChange] = ret;
}

void solve(int caseno)
{
    ll n, i, x, y, cur, sz, tempL;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        adj[i].clear();
        dp[i][0] = dp[i][1] = -1;
    }

    for(i = 1; i <= n; i++)    
        cin >> L[i] >> A[i] >> R[i];
    
    for(i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    for(cur = 1; cur <= n; cur++)
    {
        sz = adj[cur].size();
        vector<ll> v;
        for(auto nxt : adj[cur])        
            v.push_back(A[nxt]);

        sort(v.begin(), v.end());

        B[cur] = v[sz/2];

        if(B[cur] < L[cur])
            B[cur] = L[cur];
        if(B[cur] > R[cur])
            B[cur] = R[cur];
    }

    // call(1, 1);
    // for(i = 1; i <= n; i++)
    // {
    //     show(i);
    //     show(dp[i][0]);
    //     show(dp[i][1]);
    //     cout << "\n";
    // }

    cout << min(call(1, 0), call(1, 1)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}