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

long long a[MAXN], prefLeft[MAXN], prefRight[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    unordered_set<long long> stLeft, stRight;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (stLeft.find(a[i]) == stLeft.end())
        {
            stLeft.insert(a[i]);
            prefLeft[i] = prefLeft[i - 1] + 1;
        }
        else
        {
            prefLeft[i] = prefLeft[i - 1];
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (stRight.find(a[i]) == stRight.end())
        {
            stRight.insert(a[i]);
            prefRight[i] = prefRight[i + 1] + 1;
        }
        else
        {
            prefRight[i] = prefRight[i + 1];
        }
    }

    long long ans = -1;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, prefLeft[i] + prefRight[i + 1]);
    }

    cout << ans << "\n";
}