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

long long r;

bool check(long long x, long long y)
{
    return x * x + x + y * y + y < r * r;
}

int getBoxCount(int pos)
{
    int low = 0, high = MAXN;
    int ret = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (check(mid, pos))
        {
            ret = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r;

    long long ans = 1;
    for (int i = 0; i <= r; i++)
    {
        ans += 4 * getBoxCount(i);
        // cout << i << ": " << getBoxCount(i) << "\n";
    }

    cout << ans << "\n";
}