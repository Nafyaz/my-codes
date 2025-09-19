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

    deque<long long> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(x);
        sum += x;

        if (dq.size() > k)
        {
            sum -= dq.front();
            dq.pop_front();
        }

        if (dq.size() == k)
            Xor ^= sum;

        x = (a*x + b) % c;
    }

    cout << Xor << "\n";
}