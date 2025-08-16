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

int p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, i, j, ans;

    cin >> n >> x;

    for (i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p, p+n);

    i = 0;
    j = n-1;
    ans = 0;
    while(i <= j)
    {
        if (i < j && p[i] + p[j] <= x)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            j--;
        }
    }

    cout << ans << "\n";
}