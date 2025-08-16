#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN];
ll Tree[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node] = arr[bg];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

void Update(ll node, ll bg, ll ed, ll idx, ll val)
{
    if(bg == ed)
    {
        Tree[node] = val;
        arr[idx] = val;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

ll Query(ll node, ll bg, ll ed, ll l, ll r)
{
    if(bg > r || ed < l)
        return 0;

    if(l <= bg && ed <= r)
        return Tree[node];

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    ll p1 = Query(leftNode, bg, mid, l, r);
    ll p2 = Query(rightNode, mid+1, ed, l, r);

    return p1 + p2;
}

void solve(ll caseno)
{
    ll n, q, i, type, a, b;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    Build(1, 1, n);

    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b;
            Update(1, 1, n, a, b);
        }
        else
        {
            cin >> a >> b;
            cout << Query(1, 1, n, a, b) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}