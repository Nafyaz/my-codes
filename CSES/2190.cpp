#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

int cross(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long val = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if (val == 0)
        return 0;

    return val / abs(val);
}

bool check(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4)
{
    long long cross1 = cross(x1, y1, x2, y2, x3, y3);
    long long cross2 = cross(x1, y1, x2, y2, x4, y4);

    return cross1 * cross2 <= 0;
}

long long dist(long long x1, long long y1, long long x2, long long y2)
{
    return (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
}

bool isInside(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    return abs(sqrt(dist(x1, y1, x3, y3)) + sqrt(dist(x2, y2, x3, y3)) - sqrt(dist(x1, y1, x2, y2))) < EPS;
}

void solve(int caseno)
{
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // if (caseno == 7415)
    //     cout << caseno << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";

    if ((y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1))
    {
        if (isInside(x1, y1, x2, y2, x3, y3) || isInside(x1, y1, x2, y2, x4, y4) || isInside(x3, y3, x4, y4, x1, y1) || isInside(x3, y3, x4, y4, x2, y2))
            cout << "YES\n";
        else
            cout << "NO\n";

        return;
    }

    if (check(x1, y1, x2, y2, x3, y3, x4, y4) && check(x3, y3, x4, y4, x1, y1, x2, y2))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T, caseno = 0;
    cin >> T;

    while (T--)
    {
        solve(++caseno);
    }
}