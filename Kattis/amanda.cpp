#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

bool lounge[MAXN], valid[MAXN];
int color[MAXN];
vector<pii> adj[MAXN];
int sz[MAXN], ones[MAXN];

bool dfs(int cur, int p, bool l)
{
    // show(cur);
    // show(p);
    // show(lounge[cur]);
    // show(valid[cur]);
    // show(color[cur]);
    // show(sz[cur]);
    // show(ones[cur]);
    // cout << "\n";

    if(color[cur] == 1)
    {
        if(lounge[cur] != l)
            return valid[cur] = 0;
            
        return 1;
    }

    lounge[cur] = l;
    color[cur] = 1;

    sz[cur] = 1;
    ones[cur] = l;

    bool ret = 1;
    for(auto [cnt, nxt] : adj[cur])
    {
        if(nxt == p || color[nxt] == 2)
            continue;
        
        if(cnt == 0)
        {
            if(l != 0 || dfs(nxt, cur, 0) == 0)
                ret = 0;
            else if(color[nxt] == 2)
            {
                sz[cur] += sz[nxt];
                ones[cur] += ones[nxt];
            }
        }
        else if(cnt == 1)
        {
            if(dfs(nxt, cur, !l) == 0)
                ret = 0;

            if(color[nxt] == 2)
            {
                ones[cur] += ones[nxt];
                sz[cur] += sz[nxt];
            }
        }
        else
        {
            if(l != 1 || dfs(nxt, cur, 1) == 0)
                return ret = 0;
            else if(color[nxt] == 2)
            {
                ones[cur] += ones[nxt];
                sz[cur] += sz[nxt];
            }
        }
    }

    // show(cur);
    // show(lounge[cur]);
    // show(valid[cur]);
    // show(color[cur]);
    // show(sz[cur]);
    // show(ones[cur]);
    // cout << "\n";

    color[cur] = 2;
    return valid[cur] = ret;
}

void solve(int caseno)
{
    int n, m, i, a, b, c, cur, ans;
    bool possible;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    // show(dfs(1, 1));
    // return;

    possible = 1;
    ans = 0;
    for(cur = 1; cur <= n; cur++)
    {
        if(color[cur])
            continue;

        for(auto [cnt, nxt] : adj[cur])
        {
            if(cnt == 0)
            {
                possible &= dfs(cur, -1, 0);
                ans += ones[cur];
                break;
            }
            else if(cnt == 2)
            {
                possible &= dfs(cur, -1, 1);
                ans += ones[cur];
                break;
            }
        }
    }

    for(cur = 1; cur <= n; cur++)
    {
        if(color[cur])
            continue;

        possible &= dfs(cur, -1, 0);

        ans += min(ones[cur], sz[cur] - ones[cur]);
    }

    if(!possible)
        cout << "impossible\n";
    else
        cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}