#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, b, ans, ed;
    vector<pair<int, int>> v;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> a >> b;

        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    ans = 0;
    ed = 1;
    for (i = 0; i < n; i++)
    {
        if (ed <= v[i].second)
        {
            ans++;
            ed = max(ed, v[i].first);
        }
    }

    cout << ans << "\n";
}