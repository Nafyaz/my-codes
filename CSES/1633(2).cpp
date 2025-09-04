#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006
#define MOD 1000000007

int dp[MAXN];

int func(int n)
{
    // cout << n << " ";
    if (n == 0)
        return dp[0] = 1;

    if (dp[n] != 0)
        return dp[n];

    for (int i = 1; i <= 6; i++)
    {
        if (i <= n)
        {
            dp[n] = (dp[n] + func(n - i)) % MOD;
        }
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << func(n) << "\n";
}