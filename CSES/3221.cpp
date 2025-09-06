#include <bits/stdc++.h>
using namespace std;

void Push(stack<pair<long long, long long>> stk, long long x) {
    if (stk.empty())
        stk.push({x, x});
    else
        stk.push({x, min(x, stk.top().second)});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c, XOR = 0;
    cin >> x >> a >> b >> c;

    stack<pair<long long, long long>> stk1, stk2;

    for (int i = 0; i < n; i++)
    {
        // cout << x << "\n";
        if (i >= k)
        {
            if (stk2.empty())
            {
                while (!stk1.empty())
                {
                    Push(stk2, stk1.top().first);
                    stk1.pop();
                }
            }

            Push(stk1, x);

            stk2.pop();

            long long mn;
            if (stk2.empty())
                mn = stk1.top().second;
            else
                mn = min(stk1.top().second, stk2.top().second);

            XOR ^= mn;
        }

        else
        {
            Push(stk1, x);

            if (i == k-1)
                XOR ^= stk1.top().second;
        }

        x = (a * x + b) % c;
    }

    cout << XOR << "\n";
}