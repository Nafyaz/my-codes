#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c, Xor = 0;
    cin >> x >> a >> b >> c;

    deque<pair<long long, long long>> dq;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            while (!dq.empty() && dq.back().second > x)
                dq.pop_back();

            dq.push_back({i, x});

            if (i == k - 1)
                Xor ^= dq.front().second;
        }
        else
        {
            while (!dq.empty() && dq.back().second > x)
                dq.pop_back();

            dq.push_back({i, x});

            if (i - k == dq.front().first)
                dq.pop_front();

            Xor ^= dq.front().second;
        }

        x = (a * x + b) % c;
    }

    cout << Xor << "\n";
}