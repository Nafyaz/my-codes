#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int x[MAXN], Tree[4*MAXN];

void build(int node, int bg, int ed) {
    if (bg == ed) {
        Tree[node] = x[bg];
        return;
    }

    int left = 2*node, right = 2*node+1;
    int mid = (bg + ed)/2;

    build(left, bg, mid);
    build(right, mid+1, ed);

    Tree[node] = min(Tree[left], Tree[right]);
}

int query(int node, int bg, int ed, int l, int r) {
    if (ed < l || bg > r)
        return INT_MAX;

    if (l <= bg && ed <= r)
        return Tree[node];

    int left = 2*node, right = 2*node+1;
    int mid = (bg + ed)/2;

    int p1 = query(left, bg, mid, l, r);
    int p2 = query(right, mid+1, ed, l, r);

    return min(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    build(1, 1, n);

    int a, b;
    while(q--) {
        cin >> a >> b;

        cout << query(1, 1, n, a, b) << "\n";
    }

    cout << "\n";
}