#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> l(n), a(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> a[i] >> r[i];
        }
        vector<vector<int>> g(n);
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            sum += abs(a[x] - a[y]);
        }
        vector<vector<long long>> dp(n, vector<long long>(2));
        function<void(int, int)> Dfs = [&](int v, int p) {
            vector<long long> c;
            for (int to : g[v]) {
                c.emplace_back(a[to]);
                if (to == p) {
                    continue;
                }
                Dfs(to, v);
                dp[v][0] += min(dp[to][0], dp[to][1]);
                dp[v][1] += dp[to][0];
            }
            int sz = (int) c.size();
            sort(c.begin(), c.end());
            long long d = c[sz / 2];
            if (d < l[v]) {
                d = l[v];
            }
            if (d > r[v]) {
                d = r[v];
            }
            for (int i = 0; i < sz; i++) {
                dp[v][1] -= abs(a[v] - c[i]);
                dp[v][1] += abs(c[i] - d);
            }
        };
        Dfs(0, -1);
        long long ans = sum + min(dp[0][0], dp[0][1]);
        cout << ans << '\n';
    }
    return 0;
}