#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 200005;

LL n;
vector<LL> fav;
vector<pLL> adj[MAXN];

LL parent[MAXN], level[MAXN], anc[MAXN][21], dist[MAXN];

void dfs(LL cur, LL p, LL l, LL di)
{
    parent[cur] = p;
    level[cur] = l;
    dist[cur] = di;

    for(auto [d, nxt] : adj[cur])
    {
        if(nxt != parent[cur])
        {
            dfs(nxt, cur, l+1, di+d);
        }
    }
}

void LCA_init()
{
    dfs(1, 1, 0, 0);

    LL i, j;
    for(i = 1; i <= n; i++)
        anc[i][0] = parent[i];

    for(j = 1; j < 21; j++)
    {
        for(i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

LL getLCA(LL u, LL v)
{
    if(level[u] < level[v])
        swap(u, v);

    LL i;
    for(i = 20; i >= 0; i--)
    {
        if(level[anc[u][i]] >= level[v])
            u = anc[u][i];
    }

    if(u == v)
        return u;

    for(i = 20; i >= 0; i--)
    {
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return parent[u];
}

LL getDist(LL u, LL v)
{
    LL l = getLCA(u, v);

    return dist[u] + dist[v] - 2*dist[l];
}

pLL dfs2(LL cur, LL p)
{
//    show(cur);
//    show(p);
//    cout << "\n";

    pLL ret = {0, cur}, temp;

    for(auto [d, nxt] : adj[cur])
    {
        if(nxt != p)
        {
            temp = dfs2(nxt, cur);
            if(temp.ff+d > ret.ff)
                ret = {temp.ff+d, temp.ss};
        }
    }

    return ret;
}

void solve(int caseno)
{
    LL q, i, c, x, y, w;
    LL dia1, dia2, ans;

    cin >> n >> q;

    for(i = 0; i < q; i++)
    {
        cin >> c;
        fav.push_back(c);
    }

    ans = 0;
    for(i = 1; i < n; i++)
    {
        cin >> x >> y >> w;

        adj[x].push_back({w, y});
        adj[y].push_back({w, x});

        ans = ans + 2*w;
    }

    LCA_init();

    dia1 = dfs2(1, -1).ss;
    dia2 = dfs2(dia1, -1).ss;

//    show(dia1);
//    show(dia2);
//    cout << "\n";

//    cout << getLCA(3, 4) << "\n";

//    for(i = 1; i <= 4; i++)
//        cout << dist[i] << " ";
//    cout << "\n";

    for(auto u : fav)
        cout << ans - max(getDist(u, dia1), getDist(u, dia2)) << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
