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

long long a[MAXN], p[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, k, b, b_st, b_ed, ans, cnt;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n);

    for (int i = 0; i < m; i++)
    {
        cin >> b;

        b_st = lower_bound(a, a+n, b-k) - a;
        b_ed = upper_bound(a, a+n, b+k) - a;

        cout << i << ": " << b_st << " " << b_ed << "\n";

        p[b_st] ++;
        p[b_ed] --;
    }

    ans = 0;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += p[i];

        if (cnt > 0)
        {
            cnt--;
            ans++;
        }
    }

    cout << ans << "\n";
}