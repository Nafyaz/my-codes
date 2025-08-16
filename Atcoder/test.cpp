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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("output2.txt", "w", stdout);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        v.push_back({l, r});
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            bool covers = false;
            for (int k = 0; k < n; k++)
            {
                if (i <= v[k].first && v[k].second <= j)
                    covers = true;
            }

            if (!covers)
            {
                cout << i << " " << j << "\n";
                // ans.push_back({i, j});
            }
        }
    }

    // cout << ans.size() << "\n";
}