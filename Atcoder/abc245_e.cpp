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

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    vector<pair<pair<int, int>, int>> v;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> d[i];

    for (int i = 0; i < n; i++)
        v.push_back({{a[i], -1}, b[i]});
    for (int i = 0; i < m; i++)
        v.push_back({{c[i], 1}, d[i]});

    sort(v.begin(), v.end(), greater<>());

    // for (auto u : v)
    // {
    //     cout << u.first.first << " " << u.first.second << " " << u.second << "\n";
    // }

    multiset<int> ms;
    for (auto u : v)
    {
        if (u.first.second == 1)
        {
            ms.insert(u.second);
            continue;
        }

        auto it = ms.lower_bound(u.second);

        if (it == ms.end())
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            ms.erase(it);
        }
    }

    cout << "Yes\n";
}