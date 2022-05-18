#include <bits/stdc++.h>
using namespace std;

template <typename T, class bin_op>
struct segment_tree
{
#define lc i * 2
#define rc i * 2 + 1
#define m (l + r) / 2

    T e; // default value
    bin_op op;
    vector<T> tr;

    segment_tree(int _n, T _e, bin_op _op) : e(_e), op(_op)
    {
        tr = vector<T>(4 * _n + 5, e);
    }

    void update(int l, int r, int i, int u, T v)
    {
        if (l == r)
        {
            tr[i] = op(tr[i], v);
        }
        else
        {
            if (u <= m)
            {
                update(l, m, lc, u, v);
            }
            else
            {
                update(m + 1, r, rc, u, v);
            }
            tr[i] = op(tr[lc], tr[rc]);
        }
    }

    T query(int l, int r, int i, int L, int R)
    {
        if (l > R || r < L || L > R)
        {
            return e;
        }
        else if (L <= l && r <= R)
        {
            return tr[i];
        }
        else
        {
            return op(query(l, m, lc, L, R),
                      query(m + 1, r, rc, L, R));
        }
    }

#undef lc
#undef rc
#undef m
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> l(n), r(n);
    segment_tree get_right(n, n, [](int u, int v)
                           { return min(u, v); });
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = a[i] < a[i + 1] ? get_right.query(1, n, 1, a[i], a[i + 1]) : 0;
        get_right.update(1, n, 1, a[i + 1], i + 1);
    }
    segment_tree get_left(n, -1, [](int u, int v)
                          { return max(u, v); });
    for (int i = 0; i < n - 1; i++)
    {
        l[i] = a[i] < a[i + 1] ? get_left.query(1, n, 1, a[i], a[i + 1]) : n - 1;
        get_left.update(1, n, 1, a[i], i);
    }
    vector<vector<pair<int, int>>> eve(n + 1), que(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        // left of query must be in (l[i], i]
        // right of query must be in [i + 1, r[i])
        // l[i] is in [-1, n - 1], r[i] is is [0, n]
        // use segment tree as prefix sum
        if (l[i] < i && i + 1 < r[i])
        {
            eve[l[i] + 1].push_back({i + 1, 1});
            eve[l[i] + 1].push_back({r[i], -1});
            eve[i + 1].push_back({i + 1, -1});
            eve[i + 1].push_back({r[i], 1});
        }
    }
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ans[i] = r - l + 1;
        que[l].push_back({r, i});
    }
    segment_tree rectangle(n, 0, plus<int>());
    for (int i = 0; i <= n; i++)
    {
        for (auto [r, val] : eve[i])
        {
            rectangle.update(0, n, 1, r, val);
        }
        for (auto [r, ind] : que[i])
        {
            ans[ind] -= rectangle.query(0, n, 1, 0, r);
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
}