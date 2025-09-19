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

    sort(t, t+n);

    int left = n / 2, right = n - left;
    unordered_map<long long, long long> leftCount, rightCount;

    dp[0][0] = 0;
    leftCount[0] = 1;
    for (int mask = 1; mask < (1 << left); mask++)
    {
        int prevMask = (mask & (mask - 1));
        int idx = Log[((mask ^ (mask - 1)) + 1) >> 1];

        dp[0][mask] = dp[0][prevMask] + t[idx];
        leftCount[dp[0][mask]] += 1;
    }

    dp[1][0] = 0;
    rightCount[0] = 1;
    for (int mask = 1; mask < (1 << right); mask++)
    {
        int prevMask = (mask & (mask - 1));
        int idx = Log[((mask ^ (mask - 1)) + 1) >> 1];

        dp[1][mask] = dp[1][prevMask] + t[left + idx];
        rightCount[dp[1][mask]] += 1;
    }

    if (rightCount.size() < leftCount.size())
        swap(leftCount, rightCount);

    long long ans = 0;
    for (auto &[k, v] : leftCount)
    {
        if (rightCount.find(x - k) != rightCount.end())
            ans += v * rightCount[x - k];
    }

    cout << ans << "\n";
}