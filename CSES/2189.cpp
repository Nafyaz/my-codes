#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long long cross = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

    if (cross == 0)
    {
        cout << "TOUCH\n";
    }
    else if (cross > 0)
    {
        cout << "LEFT\n";
    }
    else
    {
        cout << "RIGHT\n";
    }
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