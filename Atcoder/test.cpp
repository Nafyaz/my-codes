#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], l, r; 
set <int> s, s2;
 
void solve() {
    s.clear();
    cin >> l >> r; 
    for (int i = l; i <= r; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }

    int mul;
    for (mul = 1; l % 2 == 0 && r % 2 == 1; l >>= 1, r >>= 1, mul <<= 1) {
        s2.clear();
        for (int i: s) 
          s2.insert(i >> 1);
        swap(s, s2);   
    }

    int ans;
    if (l % 2 == 0) 
      ans = r;
    else 
      ans = l;

    for (int i: s) {
        if (s.find(i ^ 1) == s.end()) {
            int cur = i ^ ans;
            bool f = true;
            for (int j : s)
                f &= ((cur ^ j) >= l && (cur ^ j) <= r);
            if (f) {
                ans = cur;
                break;
            }
        }
    }
    cout << ans * mul << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}