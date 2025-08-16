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
#define MAXN 400005

vector<pair<int, int>> times;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, b, cnt, mx;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> a >> b;

        times.push_back({a, 1});
        times.push_back({b, -1});
    }

    sort(times.begin(), times.end());

    cnt = mx = 0;
    for (i = 0; i < times.size(); i++)
    {
        cnt += times[i].second;
        mx = max(mx, cnt);
    }

    cout << mx << "\n";
}