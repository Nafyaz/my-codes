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

long long D[MAXN];

long long nCr(long long n, long long r)
{
    if (n < r)
        return 0;

    r = min(r, n - r);

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}

long long getDerange(long long n)
{
    if (n == 0)
        return D[1] = 1;
    if (n == 1)
        return D[2] = 0;
    if (D[n] != 0)
        return D[n];

    return (n - 1) * (getDerange(n - 1) + getDerange(n - 2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k, ans = 0;

    cin >> n >> k;

    for (; k >= 0; k--)
        ans += nCr(n, k) * getDerange(k);

    cout << ans << "\n";
}