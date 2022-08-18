#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define MAXN 10004

int n;
vector<int> adj[MAXN];
int parent[MAXN], level[MAXN], anc[MAXN][21];//for lca
int heavy[MAXN], subsize[MAXN];
int chainHead[MAXN], chainNo, basePos[MAXN], chainIdx[MAXN];//for hld
int base[MAXN], cnt, tree[MAXN*4], lazy[MAXN*4];//for segment tree

int dfs(int node, int pr, int l)
{
    subsize[node] = 1;
    parent[node] = pr;
    level[node] = l;

    int mx = 0, x;

    for(auto nxt : adj[node])
    {
        if(nxt != parent[node])
        {
            x = dfs(nxt, node, l+1);
            subsize[node] += x;

            if(mx < x)
            {
                heavy[node] = nxt;
                mx = x;
            }
        }
    }

    return subsize[node];
}

void lca_init()
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= 20; j++)
            anc[i][j] = 1;
    }

    for(i = 1; i <= n; i++)
        anc[i][0] = parent[i];

    for(j = 1; j <= 20; j++)
    {
        for(i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

int lca(int u, int v)
{
    if(level[u] < level[v])
        swap(u, v);

    int i;
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

void hld_init(int node, int pr)
{
	if(chainHead[chainNo] == -1)
        chainHead[chainNo] = node;

	chainIdx[node] = chainNo;
	base[cnt] = 0;
	basePos[node] = cnt;
	cnt++;

	if(heavy[node] > -1)
        hld_init(heavy[node], node);
	for(auto nxt : adj[node])
	{
		if(nxt != pr and nxt != heavy[node])
		{
			chainNo++;
			hld_init(nxt, node);
		}
	}
}

void build_tree(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = 0;
        lazy[node] = 0;
        return;
    }

    int mid = (s+e)/2, left = 2*node, right = 2*node+1;

    build_tree(left, s, mid);
    build_tree(right, mid+1, e);

    tree[node]= tree[left] + tree[right];
    lazy[node] = 0;
}

void update_tree(int node, int s, int e, int l, int r, int val)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (s + e)/2;

    if(lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];
        if(s != e)
        {
            lazy[leftNode] += lazy[node];
            lazy[rightNode] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(s > r || e < l)
        return;

    if(l <= s && e <= r)
    {
        tree[node] += (e - s + 1) * val;
        if(s != e)
        {
            lazy[leftNode] += val;
            lazy[rightNode] += val;
        }
        return;
    }

    update_tree(leftNode, s, mid, l, r, val);
    update_tree(rightNode, mid+1, e, l, r, val);

    tree[node] = tree[leftNode] + tree[rightNode];
}

int query_tree(int node, int s, int e, int l, int r)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (s + e)/2;

    if(lazy[node] != 0)
    {
        tree[node] += (e - s + 1) * lazy[node];
        if(s != e)
        {
            lazy[leftNode] += lazy[node];
            lazy[rightNode] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(s > r || e < l)
        return 0;

    if(l <= s && e <= r)
        return tree[node];

    ll p1 = query_tree(leftNode, s, mid, l, r);
    ll p2 = query_tree(rightNode, mid + 1, e, l, r);

    return (p1 + p2);
}

void update_up(int u, int p, int val)
{
    int uchain, pchain = chainIdx[p], ret = 0;

	while(1)
    {
		uchain = chainIdx[u];

		if(uchain == pchain)
		{
			update_tree(1, 1, n, basePos[p], basePos[u], val);
			break;
		}
		update_tree(1, 1, n, basePos[chainHead[uchain]], basePos[u], val);
		u = chainHead[uchain];
		u = parent[u];
	}
}

void update_hld(int u, int v)
{
    int l = lca(u, v);
    update_up(u, l, 1);
    update_up(v, l, 1);
    update_up(l, l, -1);
}

int query_up(int u, int p)
{
	int uchain, pchain = chainIdx[p], ret = 0;

	while(1)
    {
		uchain = chainIdx[u];

		if(uchain == pchain)
		{
			ret += query_tree(1, 1, n, basePos[p], basePos[u]);
			break;
		}
		ret += query_tree(1, 1, n, basePos[chainHead[uchain]], basePos[u]);
		u = chainHead[uchain];
		u = parent[u];
	}
	return ret;
}

int query_hld(int u, int v)
{
    int l = lca(u, v);
    return query_up(u, l) + query_up(v, l) - query_up(l, l);
}

void init()
{
    int i;
    for(i = 0; i <= n; i++)
    {
        heavy[i] = -1;
        chainHead[i] = -1;
    }
    dfs(1, 1, 0);
    lca_init();
    cnt = 1, chainNo = 1;
    hld_init(1, 1);
    build_tree(1, 1, n);
}

void solve(int caseno)
{
    int i, q, u, v, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
        adj[i].clear();

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    init();

    cout << "Case " << caseno << ":\n";
    cin >> q;

    while(q--)
    {
        int k, x, y, l, dist, mnDist, mnX, mnY, mnL;

        build_tree(1, 1, n);

        cin >> k;

        mnDist = 2*n;
        for(i = 1; i <= k; i++)
        {
            cin >> x >> y;

            l = lca(x, y);
            dist = level[x] + level[y] - 2*level[l];

            if(dist < mnDist)
            {
                mnDist = dist;
                mnX = x;
                mnY = y;
                mnL = l;
            }

            update_hld(x, y);
        }

        ans = (query_tree(1, 1, n, mnL, mnL) == k);
        for(i = mnX; i != mnL; i = parent[i])
            ans += (query_tree(1, 1, n, i, i) == k);
        for(i = mnY; i != mnL; i = parent[i])
            ans += (query_tree(1, 1, n, i, i) == k);

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
/*
1
6
1 2
2 3
3 4
2 5
2 6
1
1
4 5
*/

/*
2
6
1 2
2 3
3 4
2 5
2 6
2
2
4 5
3 6
3
4 5
3 1
2 6
2
1 2
1
2
1 1
2 2
*/
