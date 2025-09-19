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
    {
        cin >> p[i].first >> p[i].second;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += p[i].first * p[(i + 1) % n].second - p[(i + 1) % n].first * p[i].second;
    }

    cout << abs(ans) << "\n";
}