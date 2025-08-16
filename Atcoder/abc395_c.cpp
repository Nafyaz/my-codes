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

    int n, a, ans = INT_MAX;
    unordered_map<int, int> pos;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (pos.find(a) != pos.end())
        {
            ans = min(ans, i - pos[a] + 1);
        }

        pos[a] = i;
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}