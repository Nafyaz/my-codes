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
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, i, a, ans, pref, mn;

    cin >> n;

    ans = LLONG_MIN;
    pref = 0;
    mn = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        ans = max(ans, a);
        pref += a;

        ans = max(ans, pref - mn);

        mn = min(mn, pref);
    }

    cout << ans << "\n";
}