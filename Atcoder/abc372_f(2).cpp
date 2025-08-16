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

pair<long long, long long> edges[51];
long long dp[MAXN], temp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, k, prev, ans;

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first --;
        edges[i].second --;
    }

    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < m; j++) {
            long long u = ((edges[j].first - i + 1)%n + n)%n;
            long long v = ((edges[j].second - i)%n + n)%n;
            temp[u] = dp[u];
            temp[v] = dp[v];
        }


        for (int j = 0; j < n; j++) {
            cout << dp[j] << " ";
        }
        cout << "\n";

        for (int j = 0; j < m; j++) {
            long long u = ((edges[j].first - i + 1)%n + n)%n;
            long long v = ((edges[j].second - i)%n + n)%n;

            dp[v] = (dp[v] + temp[u]) % MOD;
        }

        for (int j = 0; j < n; j++) {
            cout << dp[j] << " ";
        }
        cout << "\n-------------------------\n";
    }

    ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << "\n";
}