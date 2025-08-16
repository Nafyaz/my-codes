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

long long a[MAXN], pref[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<long long, long long> freq;
    long long ans = 0;
    freq[0] = 1;
    for (int i = 1; i <= 2 * n - 2; i++)
    {
        pref[i] = (pref[i - 1] + a[(i - 1) % n]) % m;

        if (i >= n - 1)
        {
            ans += freq[pref[i]];
            // cout << i << " " << ans << "\n";
            freq[pref[i + 1 - n]]--;
        }

        freq[pref[i]]++;
    }

    // for (int i = 0; i <= 2 * n - 1; i++)
    //     cout << pref[i] << " ";

    cout << ans << "\n";
}