#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> v;

    v.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        v.push_back({l, r});
    }
    v.push_back({m + 1, m + 1});

    sort(v.begin(), v.end(), cmp);

    long long ans = 0;
    for (int i = 1, j = 0, mx = 0; i <= m; i++)
    {
        while (i >= v[j + 1].second)
        {
            j++;
            mx = max(mx, v[j].first);
        }

        ans += i - mx;
    }

    cout << ans << "\n";
}