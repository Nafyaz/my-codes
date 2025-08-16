#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 1000006

ll arr[maxN];
ll Tree[4*maxN], Lazy[4*maxN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Lazy[node] = 0;
        Tree[node] = arr[bg];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
    Lazy[node] = 0;
}

void updateRange(ll node, ll bg, ll ed, ll l, ll r, ll val)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += (ed - bg + 1) * Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return;

    if(l <= bg && ed <= r)
    {
        Tree[node] += (ed - bg + 1) * val;
        if(bg != ed)
        {
            Lazy[leftNode] += val;
            Lazy[rightNode] += val;
        }
        return;
    }

    updateRange(leftNode, bg, mid, l, r, val);
    updateRange(rightNode, mid+1, ed, l, r, val);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

ll queryRange(ll node, ll bg, ll ed, ll l, ll r)
{    
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += (ed - bg + 1) * Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
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

void solve(ll caseno)
{
    bool type;
    ll n, c, p, q, v;

    cin >> n >> c;

    fill(arr+1, arr+n+1, 0);    
    Build(1, 1, n);

    while(c--)
    {
        cin >> type;

        if(type)
        {
            cin >> p >> q;
            cout << queryRange(1, 1, n, p, q) << "\n";
        }
        else
        {
            cin >> p >> q >> v;
            updateRange(1, 1, n, p, q, v);
        }
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