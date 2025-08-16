#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int leader[MAXN];
set<int> st[MAXN];

int Find(int x)
{
    if (x == leader[x])
        return x;

    return leader[x] = Find(leader[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x > y)
        swap(x, y);

    set<int>::iterator it = st[y].begin();
    int i = 0;
    while (it != st[y].end() && i < 10)
    {
        st[x].insert(*it);

        it++;
        i++;
    }

    leader[y] = x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        leader[i] = i;
        st[i].insert(-i);
    }

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int u, v;

            cin >> u >> v;

            Union(u, v);
        }
        else
        {
            int v, k;

            cin >> v >> k;

            v = Find(v);

            if (st[v].size() < k)
                cout << -1 << "\n";
            else
            {
                set<int>::iterator it = st[v].begin();

                k--;
                while (k--)
                    it++;

                cout << -*it << "\n";
            }
        }
    }
}