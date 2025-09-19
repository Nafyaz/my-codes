#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c, Xor, last, ans;
    cin >> x >> a >> b >> c;

    Xor = 0;
    last = x;
    ans = 0;

    for (int i = 1; i <= n; i++)
    {
        Xor ^= x;

        if (i >= k)
        {
            if (i > k)
            {
                Xor ^= last;
                last = (last * a + b) % c;
            }

            ans ^= Xor;
        }

        x = (x * a + b) % c;
    }

    cout << ans << "\n";
}