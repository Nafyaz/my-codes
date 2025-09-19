#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> p[1003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    long long ans = 0;
    for (int i = 1; i + 1 < n; i++)
        ans += (p[0].first * p[i].second + p[i].first * p[i + 1].second + p[i + 1].first * p[0].second) - (p[0].second * p[i].first + p[i].second * p[i + 1].first + p[i + 1].second * p[0].first);

    cout << abs(ans) << "\n";
}

x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3