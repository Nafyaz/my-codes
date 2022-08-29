#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 100005;

LL arr[MAXN], pref[MAXN];
LL Tree[4*MAXN], Lazy[4*MAXN];

//void Build(LL node, LL bg, LL ed)
//{
//    if(bg == ed)
//    {
//        Lazy[node] = 0;
//        Tree[node] = arr[bg];
//        return;
//    }
//
//    LL leftNode = 2*node, rightNode = 2*node + 1;
//    LL mid = (bg + ed)/2;
//
//    Build(leftNode, bg, mid);
//    Build(rightNode, mid+1, ed);
//
//    Tree[node] = Tree[leftNode] + Tree[rightNode];
//    Lazy[node] = 0;
//}

void updateRange(LL node, LL bg, LL ed, LL l, LL r, LL val)
{
    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

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

LL queryRange(LL node, LL bg, LL ed, LL l, LL r)
{
    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

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

    LL p1 = queryRange(leftNode, bg, mid, l, r);
    LL p2 = queryRange(rightNode, mid + 1, ed, l, r);

    return (p1 + p2);
}

void solve(int caseno)
{
    LL n, c, i, s, e;

    cin >> n >> c;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }

    s = e = 1;
    updateRange(1, 1, n, s, e, 1);

    while(s <= n)
    {
        if(e == n)
            s++;
        else if(pref[e+1] - pref[s-1] > c)
            s++;
        else
            e++;

        if(s <= e)
            updateRange(1, 1, n, s, e, 1);
    }

    for(i = 1; i <= n; i++)
        cout << queryRange(1, 1, n, i, i) << "\n";
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

