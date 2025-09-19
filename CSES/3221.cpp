#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
    stack<pair<T, T>> stk;

public:
    bool empty()
    {
        return stk.empty();
    }

    void push(T x)
    {
        if (stk.empty())
            stk.push({x, x});
        else
            stk.push({x, min(x, stk.top().second)});
    }

    void pop()
    {
        stk.pop();
    }

    pair<T, T> top()
    {
        return stk.top();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c, XOR = 0;
    cin >> x >> a >> b >> c;

    Stack<long long> stk1, stk2;

    for (int i = 0; i < n; i++)
    {
        // cout << x << "\n";
        if (i >= k)
        {
            if (stk2.empty())
            {
                while (!stk1.empty())
                {
                    stk2.push(stk1.top().first);
                    stk1.pop();
                }
            }

            stk1.push(x);
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
            stk1.push(x);

            if (i == k - 1)
                XOR ^= stk1.top().second;
        }

        x = (a * x + b) % c;
    }

    cout << XOR << "\n";
}