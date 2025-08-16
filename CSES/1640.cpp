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

pair<int, int> a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, i, j;

    cin >> n >> x;

    for (i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort (a, a+n);

    i = 0;
    j = n-1;
    while(i < j)
    {
        if (a[i].first + a[j].first > x)
            j--;
        else if (a[i].first + a[j].first < x)
            i++;
        else
        {
            cout << a[i].second << " " << a[j].second << "\n";
            return 0;
        }

        // cout << i << " " << j << "\n";
    }

    cout << "IMPOSSIBLE\n";
}