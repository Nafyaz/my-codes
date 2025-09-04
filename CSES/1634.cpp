#include<bits/stdc++.h>
using namespace std;

int c[102], dp[1000006];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int sum = 1; sum <= x; sum++) {
        for (int i = 0; i < n; i++) {
            if (sum >= c[i] && dp[sum-c[i]] != -1) {
                if (dp[sum] == -1)
                    dp[sum] = dp[sum-c[i]] + 1;
                else
                    dp[sum] = min(dp[sum-c[i]] + 1, dp[sum]);
            }
        }
    }

    cout << dp[x] << "\n";
}