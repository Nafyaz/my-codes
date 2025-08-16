#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

unordered_map<int, double> probs[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int faceCount;
        unordered_map<int, int> freq;

        cin >> faceCount;
        for (int j = 1; j <= faceCount; j++)
        {
            int a;
            cin >> a;

            freq[a]++;
        }

        for (const auto [k, v] : freq)
            probs[i][k] = 1.0 * v / faceCount;
    }

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double total = 0;
            int small = i, large = j;
            if (probs[small].size() > probs[large].size())
                swap(small, large);

            for (const auto [k, v] : probs[small])
                total += v * probs[large][k];

            ans = max(ans, total);
        }
    }

    cout << setprecision(15) << ans << "\n";
}