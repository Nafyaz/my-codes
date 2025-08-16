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

int a[MAXN];
int Tree[4*MAXN], LAZY[4*MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}