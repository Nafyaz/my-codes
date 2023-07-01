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
LL sz[MAXN], total;
LL leader[MAXN], maxEdge[MAXN];

LL add(LL u, LL v, LL w)
{
    LL mx = 0;

    while(leader[u] != u && leader[v] != v && u != v)
    {
        if(leader[u] == u || (leader[v] != v && sz[v] <= sz[u]))
        {
            mx = max(mx, maxEdge[v];)
            v = leader[v];
        }
        else
        {
            mx = max(mx, maxEdge[u]);
            u = leader[u];
        }
    }

    if(u == v)
        return w - mx;

    if(sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    leader[v] = u;
    maxEdge[v] = w;

    mst += w;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL u, v, w, i;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;

        edges.push_back(edge({w, u, v, i}));
        sz[i] = 1;
    }

    for(i = 1; i <= n; i++)
        leader[i] = i;

    sort(edges.begin(), edges.end());
    for(i = 0; i < m; i++)
        ans[edges[i].idx] = add(edges[i].node1, edges[i].node2, edges[i].weight);
    
    for(i = 1; i <= n; i++)
        cout << total + ans[i] << "\n";
}