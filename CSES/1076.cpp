#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

int x[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    ordered_set<pair<int, int>> OS;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        OS.insert({x[i], i});

        if (i >= k-1) {
            OS.erase({x[i-k], i-k});
            cout << OS.find_by_order((k-1)/2) -> first << " ";
        }
    }
    
    cout << "\n";
}