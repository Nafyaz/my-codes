#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000006

long long t[41];
long long dp[2][MAXN], Log[MAXN];

void init()
{
    Log[1] = 0;
    for (int i = 2; i < MAXN; i *= 2)
        Log[i] = Log[i / 2] + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    init();

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    int left = n / 2, right = n - left;
    vector<long long> leftSum, rightSum;

    dp[0][0] = 0;
    leftSum.push_back(0);
    for (int mask = 1; mask < (1 << left); mask++)
    {
        int prevMask = (mask & (mask - 1));
        int idx = Log[((mask ^ (mask - 1)) + 1) >> 1];

        dp[0][mask] = dp[0][prevMask] + t[idx];
        leftSum.push_back(dp[0][mask]);
    }

    dp[1][0] = 0;
    rightSum.push_back(0);
    for (int mask = 1; mask < (1 << right); mask++)
    {
        int prevMask = (mask & (mask - 1));
        int idx = Log[((mask ^ (mask - 1)) + 1) >> 1];

        dp[1][mask] = dp[1][prevMask] + t[left + idx];
        rightSum.push_back(dp[1][mask]);
    }

    sort(leftSum.begin(), leftSum.end());
    sort(rightSum.begin(), rightSum.end());

    // for (auto u : leftSum)
    //     cout << u << " ";
    // cout << "\n";
    // for (auto u : rightSum)
    //     cout << u << " ";
    // cout << "\n";
    // return 0;

    long long ans = 0;
    int leftIdx = 0, rightIdx = rightSum.size()-1;
    while(leftIdx < leftSum.size() && rightIdx >= 0) {
        while(rightIdx >= 0 && leftSum[leftIdx] + rightSum[rightIdx] > x)
            rightIdx--;
        
        while (rightIdx >= 0 && leftSum[leftIdx] + rightSum[rightIdx] == x)
        {
            ans++;
            rightIdx--;
        }

        leftIdx++;
    }

    cout << ans << "\n";
}