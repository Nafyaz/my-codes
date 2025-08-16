#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

long long a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, x, mn, mnIdx, val;

    cin >> n >> x;

    mn = LLONG_MAX;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] < mn)
            mn = a[i];
    }

    // show(mn);

    val = 0;
    for (int i = x-1; ; i = (i-1+n)%n)
    {
        if (a[i] == mn)
        {
            mnIdx = i;
            break;
        }
        val++;
        a[i]--;
    }

    // show(mnIdx);

    val += a[mnIdx] * n;
    mn = a[mnIdx];
    for (int i = 0; i < n; i++)
        a[i] -= mn;

    a[mnIdx] = val;

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}