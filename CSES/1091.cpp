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

int h[MAXN], lead[MAXN];

int Find(int x)
{
    if (x == lead[x])
        return x;
    return lead[x] = Find(lead[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    lead[max(x, y)] = min(x, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, t, pos;

    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        cin >> h[i];
        lead[i] = i;
    }

    sort(h+1, h+n+1);

    for (i = 0; i < m; i++)
    {
        cin >> t;

        pos = upper_bound(h+1, h+n+1, t) - h-1;
        
        if (Find(pos) == 0)
            cout << "-1\n";
        else
        {
            cout << h[Find(pos)] << "\n";
            Union(Find(pos), Find(pos)-1);
        }

        // cout << "pos: " << pos << "; ";
        // for (int j = 0; j <= n; j++)
        //     cout << lead[j] << " ";
        // cout << "\n";
    }
}