#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005

ll Tree[4*MAXN], Lazy[4*MAXN];
vector<ll> pos[MAXN];

//void Build(ll node, ll bg, ll ed)
//{
//    if(bg == ed)
//    {
//        Lazy[node] = 0;
//        Tree[node] = pref[bg];
//        return;
//    }
//
//    ll leftNode = 2*node, rightNode = 2*node + 1;
//    ll mid = (bg + ed)/2;
//
//    Build(leftNode, bg, mid);
//    Build(rightNode, mid+1, ed);
//
//    Tree[node] = min(Tree[leftNode], Tree[rightNode]);
//    Lazy[node] = 0;
//}

void updateRange(ll node, ll bg, ll ed, ll l, ll r, ll val)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += Lazy[node];
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
        Tree[node] += val;
        if(bg != ed)
        {
            Lazy[leftNode] += val;
            Lazy[rightNode] += val;
        }
        return;
    }

    updateRange(leftNode, bg, mid, l, r, val);
    updateRange(rightNode, mid+1, ed, l, r, val);

    Tree[node] = min(Tree[leftNode], Tree[rightNode]);
}

ll queryRange(ll node, ll bg, ll ed, ll l, ll r)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return INT_MAX;

    if(l <= bg && ed <= r)
        return Tree[node];

    ll p1 = queryRange(leftNode, bg, mid, l, r);
    ll p2 = queryRange(rightNode, mid + 1, ed, l, r);

    return min(p1, p2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, i, ans, sz, pref;

    cin >> n;

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a;

        sz = pos[a].size();
        if(sz == 0)
        {
            updateRange(1, 1, n, i, n, 1);
            pref = queryRange(1, 1, n, i, i);
            ans = max(ans, pref - min(0LL, queryRange(1, 1, n, 1, i-1)));

            pos[a].push_back(i);
        }
        else if(sz == 1)
        {
            updateRange(1, 1, n, pos[a][sz-1], n, -2);
            updateRange(1, 1, n, i, n, 1);

            pref = queryRange(1, 1, n, i, i);
            ans = max(ans, pref - min(0LL, queryRange(1, 1, n, 1, i-1)));

            pos[a].push_back(i);
        }
        else
        {
            updateRange(1, 1, n, pos[a][sz-2], n, 1);
            updateRange(1, 1, n, pos[a][sz-1], n, -2);
            updateRange(1, 1, n, i, n, 1);

            pref = queryRange(1, 1, n, i, i);
            ans = max(ans, pref - min(0LL, queryRange(1, 1, n, 1, i-1)));

            pos[a].push_back(i);
        }
    }

    cout << ans << "\n";
}
