#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n, c[1000006], dp[1000006];

int func(int x) {
    if (x == 0)
        return dp[x] = 1;

    if (dp[x] != -1)
        return dp[x];

    dp[x] = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] <= x) {
            dp[x] = (dp[x] + func(x-c[i])) % MOD;
        }
    }

    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int x;

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    memset(dp, -1, sizeof dp);
    cout << func(x) << "\n";
}