#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
//    vector<int> w(N), v(N);
    int w[N+1], v[N+1];
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    // Create a 2D array to store the maximum value
    // we can get by considering the first i items
    // and a knapsack of capacity j
//    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));
    int dp[N+1][W+1] = {0};

    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= N; i++)
    {
        // cout << w[i] << " " << v[i] << ": ";
        for(int j = 0; j <= W; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    // Fill up the dp array row by row
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            // If the weight of the current item is less than or equal to j,
            // we have two choices: either we take it or we don't
            if (w[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            } else {
                // If the weight of the current item is greater than j,
                // we cannot take it
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        // cout << w[i] << " " << v[i] << ": ";
        for(int j = 0; j <= W; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    // The maximum value we can get is stored in dp[N][W]
    cout << dp[N][W] << endl;

    return 0;
}