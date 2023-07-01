#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 200005

vector<pll> walls[MAXN];
ll Tree[4*MAXN], Lazy[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Lazy[node] = 0;
        Tree[node] = 1;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Lazy[node] = 0;
    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

void updateRange(ll node, ll bg, ll ed, ll l, ll r)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] = 0;
        if(bg != ed)
        {
            Lazy[leftNode] = 1;
            Lazy[rightNode] = 1;
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return;

    if(l <= bg && ed <= r)
    {
        Tree[node] = 0;
        if(bg != ed)
        {
            Lazy[leftNode] = 1;
            Lazy[rightNode] = 1;
        }
        return;
    }

    updateRange(leftNode, bg, mid, l, r);
    updateRange(rightNode, mid+1, ed, l, r);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

void updatePoint(ll node, ll bg, ll ed, ll idx)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] = 0;
        if(bg != ed)
        {
            Lazy[leftNode] = 1;
            Lazy[rightNode] = 1;
        }
        Lazy[node] = 0;
    }

    if(bg > idx || ed < idx)
        return;

    if(bg == ed)
    {
        Tree[node] = 1;
        return;
    }

    updatePoint(leftNode, bg, mid, idx);
    updatePoint(rightNode, mid+1, ed, idx);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

ll queryRange(ll node, ll bg, ll ed, ll l, ll r)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] = 0;
        if(bg != ed)
        {
            Lazy[leftNode] = 1;
            Lazy[rightNode] = 1;
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return 0;

    if(l <= bg && ed <= r)
        return Tree[node];

    ll p1 = queryRange(leftNode, bg, mid, l, r);
    ll p2 = queryRange(rightNode, mid + 1, ed, l, r);

    return (p1 + p2);
}

void solve(int caseno)
{
    int n, q, i, x1, x2, y;

    cin >> n >> q;

    for(i = 1; i <= n-1; i++)
        walls[i].clear();

    for(i = 0; i < q; i++)
    {
        cin >> x1 >> x2 >> y;
        walls[y].push_back({x1, x2});
    }

    Build(1, 1, n);

    for(i = 1; i <= n-1; i++)
    {
        for(auto w : walls[i])
        {
            if(queryRange(1, 1, n, w.ff, w.ss) != 0)
            {
                updateRange(1, 1, n, w.ff, w.ss);

                updatePoint(1, 1, n, w.ff);
                updatePoint(1, 1, n, w.ss);
            }
        }
    }

    cout << queryRange(1, 1, n, 1, n) << "\n";
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

