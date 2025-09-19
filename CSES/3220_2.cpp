#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c, sum = 0, Xor = 0;
    cin >> x >> a >> b >> c;

    long long last = x;
    for (int i = 1; i <= n; i++) {
        sum += x;

        if (i > k) {
            sum -= last;
            last = (last * a + b) % c;
        }

        if (i >= k)
            Xor ^= sum;

        x = (x * a + b) % c;
    }

    cout << Xor << "\n";
}