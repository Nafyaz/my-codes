#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int n, s, t;
struct segment
{
    pair<int, int> endPoint1;
    pair<int, int> endPoint2;
    double inTime;
};

vector<segment> segments;

double getDist(pair<int, int> pos1, pair<int, int> pos2)
{
    return sqrt((pos1.first - pos2.first) * (pos1.first - pos2.first) + (pos1.second - pos2.second) * (pos1.second - pos2.second));
}

double func(pair<int, int> pos, int mask)
{
    if (mask == (1 << n) - 1)
        return 0;

    double ret = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            continue;

        double outTime1 = getDist(pos, segments[i].endPoint1) / s;
        ret = min(ret, outTime1 + segments[i].inTime + func(segments[i].endPoint2, mask | (1 << i)));

        double outTime2 = getDist(pos, segments[i].endPoint2) / s;
        ret = min(ret, outTime2 + segments[i].inTime + func(segments[i].endPoint1, mask | (1 << i)));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> t;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> endPoint1, endPoint2;

        cin >> endPoint1.first >> endPoint1.second;
        cin >> endPoint2.first >> endPoint2.second;

        segments.push_back({endPoint1, endPoint2, getDist(endPoint1, endPoint2) / t});
    }

    cout << fixed << setprecision(20) << func({0, 0}, 0) << "\n";
}