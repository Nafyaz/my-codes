#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

long long x[MAXN], Tree[4 * MAXN];

void build(int node, int st, int ed)
{
    if (st == ed)
    {
        Tree[node] = x[st];
        return;
    }

    int left = 2 * node, right = 2 * node + 1;
    int mid = (st + ed) / 2;

    build(left, st, mid);
    build(right, mid + 1, ed);

    Tree[node] = Tree[left] + Tree[right];
}

void update(int node, int st, int ed, int idx, int val)
{
    if (ed < idx || st > idx)
        return;

    if (st == ed)
    {
        Tree[node] = val;
        return;
    }

    int left = 2 * node, right = 2 * node + 1;
    int mid = (st + ed) / 2;

    update(left, st, mid, idx, val);
    update(right, mid + 1, ed, idx, val);

    Tree[node] = Tree[left] + Tree[right];
}

long long query(int node, int st, int ed, int l, int r)
{
    if (st > r || ed < l)
        return 0;

    if (l <= st && ed <= r)
        return Tree[node];

    int left = 2 * node, right = 2 * node + 1;
    int mid = (st + ed) / 2;

    return query(left, st, mid, l, r) + query(right, mid + 1, ed, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    build(1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int k, u;
            cin >> k >> u;

            update(1, 1, n, k, u);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
}