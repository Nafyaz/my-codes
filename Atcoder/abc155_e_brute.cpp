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

int get_sum(int n)
{
    if (!n)
        return 0;

    return n % 10 + get_sum(n / 10);
}

int opti(int n)
{
    if (!n)
        return 0;

    int digit = n % 10;

    return min(digit, 11 - digit) + opti(n / 10);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int n = 1; n <= 1000; n++)
    {
        int mn = INT_MAX;
        for (int i = n; i <= 100; i++)
            mn = min(mn, get_sum(i) + get_sum(i - n));

        if (mn != opti(n))
            cout << n << ": " << mn << "\n";
    }
}