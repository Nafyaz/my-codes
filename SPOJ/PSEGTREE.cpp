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
#define MAXN 2000006
 
struct Node 
{
    Node *l, *r;
    int sum;
 
    Node(int val) : l(nullptr), r(nullptr), sum(val) {}
    Node(Node *l, Node *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
 
int a[MAXN];
Node *root[MAXN];
 
Node* Build(int bg, int ed) 
{
    if (bg == ed)
        return new Node(a[bg]);
    int mid = (bg + ed) / 2;
    return new Node(Build(bg, mid), Build(mid+1, ed));
}
 
int Query(Node* v, int bg, int ed, int l, int r) 
{
    if (l > ed || r < bg)
        return 0;
    if (l <= bg && ed <= r)
        return v->sum;
    int mid = (bg + ed) / 2;
    return Query(v->l, bg, mid, l, r) + Query(v->r, mid+1, ed, l, r);
}
 
Node* Update(Node* v, int bg, int ed, int pos, int new_val) 
{
    if (bg == ed)
        return new Node(v->sum + new_val);
    int mid = (bg + ed) / 2;
    if (pos <= mid)
        return new Node(Update(v->l, bg, mid, pos, new_val), v->r);
    else
        return new Node(v->l, Update(v->r, mid+1, ed, pos, new_val));
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, i, q, type, cnt1;
    int idx, pos, v, l, r;
 
    cin >> n;
 
    for(i = 0; i < n; i++)
        cin >> a[i];
 
    root[0] = Build(0, n-1);
 
    cin >> q;
 
    cnt1 = 0;
    while(q--)
    {
        cin >> type;
 
        if(type == 1)
        {
            cin >> idx >> pos >> v;
 
            cnt1++;
            root[cnt1] = Update(root[idx], 0, n-1, pos-1, v);
        }
        else
        {
            cin >> idx >> l >> r;
 
            cout << Query(root[idx], 0, n-1, l-1, r-1) << "\n";
        }
    }
} 