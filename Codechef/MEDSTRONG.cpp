#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 200005

LL color[MAXN], sz[MAXN], hasInDegree[MAXN];
vector<LL> g[MAXN], gr[MAXN];
bool vis[MAXN];
vector<LL> order;
vector<vector<LL>> components;

void dfs1(LL node)
{
    vis[node] = 1;
    for(auto nxt : g[node])
    {
        if(!vis[nxt])
            dfs1(nxt);
    }

    order.push_back(node);
}

void dfs2(LL node, LL c)
{
    vis[node] = 1;
    color[node] = c;
    sz[c] ++;
    for(auto nxt : gr[node])
    {
        if(!vis[nxt])
            dfs2(nxt, c);
    }
}

void dfs3(LL node)
{
    vis[node] = 1;
    for(auto nxt : g[node])
    {
        if(!vis[nxt])
        {
            if(color[node] != color[nxt])
                hasInDegree[color[nxt]] = 1;
            dfs3(nxt);
        }
    }
}

LL bigmod(LL a, LL p)
{
    if(p == 0)
        return 1;

    LL ret = bigmod(a, p/2);
    ret = (ret*ret) % MOD;

    if(p&1)
        ret = (ret*a) % MOD;

    return ret;
}

void solve(int caseno)
{
    LL n, m, i, a, b, c, ans;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        g[i].clear();
        gr[i].clear();
        sz[i] = 0;
        hasInDegree[i] = 0;
    }
    order.clear();
    components.clear();

    for(i = 1; i <= n; i++)
    {
        cin >> a >> b;

        g[b].push_back(a);
        gr[a].push_back(b);
    }

    fill(vis, vis+m+1, 0);
    for(i = 1; i <= m; i++)
    {
        if(!vis[i])
            dfs1(i);
    }

    // for(auto u : order)
    //     cout << u << " ";
    // cout << "\n";

    fill(vis, vis+m+1, 0);
    c = 1;
    for(i = m-1; i >= 0; i--)
    {
        if(!vis[order[i]])
        {
            dfs2(order[i], c);
            c++;
        }
    }

    fill(vis, vis+m+1, 0);
    for(i = m-1; i >= 0; i--)
    {
        if(!vis[order[i]])
            dfs3(order[i]);
    }

    // for(i = 1; i < c; i++)
    // {
    //     show(sz[i]);
    //     show(hasInDegree[i]) << "\n";
    // }

    ans = 1;
    for(i = 1; i < c; i++)
        ans = (ans*(bigmod(2, sz[i]) - !hasInDegree[i] + MOD)) % MOD;

    cout << ans << "\n";
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