#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long bigmod(long long a, long long p, long long mod)
{
    long long ret = 1;

    while (p)
    {
        if (p & 1)
            ret = (ret * a) % mod;

        a = (a * a) % mod;
        p >>= 1;
    }

    return ret;
}

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;

    cout << bigmod(a, bigmod(b, c, MOD - 1), MOD) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
}