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

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    unordered_set<int> stEven, stOdd;
    for (int i = 0, j = 0; i < n; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            j = i + 2;
            stEven.clear();
            continue;
        }

        while (stEven.find(a[i]) != stEven.end())
        {
            stEven.erase(a[j]);
            j += 2;
        }

        ans = max(ans, i - j + 2);
        stEven.insert(a[i]);
    }

    for (int i = 1, j = 1; i < n - 1; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            j = i + 2;
            stOdd.clear();
            continue;
        }

        while (stOdd.find(a[i]) != stOdd.end())
        {
            stOdd.erase(a[j]);
            j += 2;
        }

        ans = max(ans, i - j + 2);
        stOdd.insert(a[i]);
    }

    cout << ans << "\n";
}