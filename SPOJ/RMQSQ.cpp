#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int a[100009], sparse[100009][20], Log[100009];

int main()
{
    int n, i, j;
    cin >> n;

    Log[1] = 0;
    for(i = 2; i <= n; i++)
        Log[i] = Log[i>>1] + 1;

//    for(i = 0; i <= n; i++)
//        cout << Log[i] << " ";

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
        sparse[i][0] = a[i];

    for(j = 1; j <= Log[n] + 1; j++)
    {
        for(i = 0; i + (1 << (j-1)) < n; i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
    }

//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j <= Log[n] + 1; j++)
//            cout << sparse[i][j] << " ";
//        cout << endl;
//    }

    int q, k;
    cin >> q;

    while(q--)
    {
        cin >> i >> j;
        k = Log[j-i+1];
        cout << min(sparse[i][k], sparse[j - (1 << k) + 1][k]) << endl;
    }
}
