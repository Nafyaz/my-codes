#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    deque<int> sorted, rev_sorted;

    long long n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        sorted.push_back(i);
    }

    while (1)
    {
        if (k >= sorted.size() - 1)
        {
            rev_sorted.push_front(sorted.front());
            sorted.pop_front();
            k -= sorted.size();
        }
        else
            break;
    }

    if (k == 0)
    {
        for (auto u : sorted)
            cout << u << " ";
    }
    else
    {
        for (int i = 1; i < sorted.size(); i++)
        {
            cout << sorted[i] << " ";

            if (i == k)
                cout << sorted[0] << " ";
        }
    }

    for (auto u : rev_sorted)
        cout << u << " ";
}