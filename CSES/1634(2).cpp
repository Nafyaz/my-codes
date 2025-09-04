#include <bits/stdc++.h>
using namespace std;

int n, c[102], dp[1000006];

int func(int x)
{
    if (x == 0)
        return dp[0] = 0;
    if (dp[x] != -2)
        return dp[x];

    dp[x] = -1;
    int val;
    for (int i = 0; i < n; i++)
    {
        if (x >= c[i])
        {
            val = func(x - c[i]);

            if (val != -1)
            {
                if (dp[x] == -1)
                    dp[x] = val + 1;
                else
                    dp[x] = min(dp[x], val + 1);
            }
        }
    }

    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int x;

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i <= x; i++)
        dp[i] = -2;

    cout << func(x) << "\n";
}