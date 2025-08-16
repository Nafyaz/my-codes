#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 998244353
#define MAXN 200005

long long a[102][MAXN];
map<long long, long long> mp, revMp;

vector<pair<long long, long long>> adj[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, k, x, y, mx = 0, prev, ans;
    
    cin >> n >> m >> k;

    mp[1] = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        if (mp.find(x) == mp.end()) {
            mx++;
            mp[x] = mx;
            revMp[mx] = x;
        }

        if (mp.find(y) == mp.end()) {
            mx++;
            mp[y] = mx;
            revMp[mx] = y;
        }

        adj[mp[x]].push_back({mp[y], 1});
    }

    prev = 1;
    for (auto const& [u, v] : mp) {
        if (u != prev) {
            adj[mp[prev]].push_back({v, u - prev});
        }

        prev = u;
    }

    adj[mp[prev]].push_back({0, n - prev + 1});

    // for (int i = 0; i < 4; i++) {
    //     cout << i << ": ";
    //     for (auto const& [u, v] : adj[i]) {
    //         cout << u << " " << v << "; ";
    //     }
    //     cout << "\n";
    // }

    a[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int u = 0; u < 102; u++) {
            for (auto const& [v, dist] : adj[u]) {
                if (i >= dist) {
                    a[v][i] = (a[v][i] + a[u][i - dist]) % MOD;
                }
            }
        }
    }

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << a[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    ans = 0;
    prev = 1;
    for (int i = 1; i <= n; i++) {
        if (mp.find(i) == mp.end()) {
            long long dist = i - prev;
            if (dist <= k) {
                ans = (ans + a[mp[prev]][k - dist]) % MOD;
            }
        } else {
            ans = (ans + a[mp[i]][k]) % MOD;
            prev = i;
        }

        // cout << i << ": " << ans << "\n";
    }
    
    cout << ans << "\n";
}