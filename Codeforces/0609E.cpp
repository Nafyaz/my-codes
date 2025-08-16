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

LL n, m;
struct edge
{
    LL weight, node1, node2, idx;

    bool operator<(const edge &e)
    {
        return weight < e.weight;
    }
};
vector<edge> edges;
LL leader[MAXN], anc[MAXN][20], level[MAXN];
vector<pLL> adj[MAXN];
LL sparse[MAXN][20];
LL ans[MAXN];

LL Find(LL x)
{
    if(leader[x] == x)
        return x;

    return Find(leader[x]);
}

void Union(LL x, LL y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;

    leader[max(x, y)] = min(x, y);
}

LL kruskal()
{
    LL i, ret = 0;

    for(i = 1; i <= n; i++)
        leader[i] = i;

    sort(edges.begin(), edges.end());
    for(auto e : edges)
    {
        if(Find(e.node1) != Find(e.node2))
        {
            ret += e.weight;
            adj[e.node1].push_back({e.weight, e.node2});
            adj[e.node2].push_back({e.weight, e.node1});
            Union(e.node1, e.node2);
        }
    }

    return ret;
}

void dfs(LL node, LL p, LL w, LL l)
{
    anc[node][0] = p;
    sparse[node][0] = w;
    level[node] = l;

    for(auto [nxtW, nxtNode] : adj[node])
    {
        if(nxtNode == p)
            continue;

        dfs(nxtNode, node, nxtW, l+1);
    }
}

LL getMax(LL x, LL y)
{
    bool flag = 0;
    if(x == 7 && y == 5)
        flag = 1;

    if(level[x] < level[y])
        swap(x, y);

    LL i, ret = 0;
    for(i = 19; i >= 0; i--)
    {
        if(level[anc[x][i]] >= level[y])
        {
            ret = max(ret, sparse[x][i]);
            x = anc[x][i];
        }
    }

    if(x == y)
        return ret;

    for(i = 19; i >= 0; i--)
    {
        if(anc[x][i] != anc[y][i])
        {
            ret = max(ret, sparse[x][i]);
            ret = max(ret, sparse[y][i]);
            
            x = anc[x][i];
            y = anc[y][i];
        }
    }

    ret = max(ret, sparse[x][0]);
    ret = max(ret, sparse[y][0]);

    x = anc[x][0];
    y = anc[y][0];

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL u, v, w, i, j, total, mx;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;

        edges.push_back({w, u, v, i});
    }

    total = kruskal();a

    dfs(1, 1, 0, 0);

    for(j = 1; j < 20; j++)
    {
        for(i = 1; i <= n; i++)
        {
            sparse[i][j] = max(sparse[i][j-1], sparse[anc[i][j-1]][j-1]);
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }

    for(i = 0; i < m; i++)
    {
        mx = getMax(edges[i].node1, edges[i].node2);
        ans[edges[i].idx] = total + edges[i].weight - mx;
    }

    for(i = 1; i <= m; i++)
        cout << ans[i] << "\n";
}