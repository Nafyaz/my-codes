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

    int n, a, idx = -1;
    unordered_map<int, int> freq, rev;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        freq[a]++;
        rev[a] = i;
    }

    for (auto const &[k, v] : freq)
    {
        if (v == 1)
            idx = max(idx, k);
    }

    cout << (idx == -1 ? -1 : rev[idx]) << "\n";
}