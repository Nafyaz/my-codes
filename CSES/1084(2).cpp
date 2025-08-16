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

long long a[MAXN];
pair<long long, long long> limit[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, k, b;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a+n);

    for (int i = 0; i < m; i++)
    {
        cin >> b;

        limit[i].first = b-k;
        limit[i].second = b+k;
    }

    sort(limit, limit+m);

    long long ans = 0;
    for (int i = 0, j = 0; i < n && j < m; i++)
    {
        while(j < m && limit[j].second < a[i])
        {
            j++;
        }

        if (j < m && limit[j].first <= a[i])
        {
            j++;
            ans++;
        }
    }

    cout << ans << "\n";
}