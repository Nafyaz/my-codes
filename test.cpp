#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int a[MAXN];

bool cmp(int x, int y)
{
    if (x%2 != y%2)
    {
        return x%2 > y%2;
    }

    if (x%2 == 0)
        return x < y;
    else
        return x > y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n, cmp);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}