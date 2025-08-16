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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    pair<long long, long long> S;

    cin >> S.first >> S.second;

    unordered_map<long long, set<long long>> housesX, housesY;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;

        housesX[x].insert(y);
        housesY[y].insert(x);
    }

    long long visitedHouseCount = 0;
    while (m--)
    {
        string direction;
        long long change;

        cin >> direction >> change;

        set<long long>::iterator st, ed;

        if (direction == "U")
        {
            st = housesX[S.first].lower_bound(S.second);
            S.second += change;
            ed = housesX[S.first].upper_bound(S.second);

            vector<long long> visitedY;
            while (st != ed)
            {
                visitedY.push_back(*st);
                visitedHouseCount++;
                st++;
            }

            for (auto y : visitedY)
            {
                housesX[S.first].erase(y);
                housesY[y].erase(S.first);
            }
        }
        else if (direction == "D")
        {
            ed = housesX[S.first].upper_bound(S.second);
            S.second -= change;
            st = housesX[S.first].lower_bound(S.second);

            vector<long long> visitedY;
            while (st != ed)
            {
                visitedY.push_back(*st);
                visitedHouseCount++;
                st++;
            }

            for (auto y : visitedY)
            {
                housesX[S.first].erase(y);
                housesY[y].erase(S.first);
            }
        }
        else if (direction == "L")
        {
            ed = housesY[S.second].upper_bound(S.first);
            S.first -= change;
            st = housesY[S.second].lower_bound(S.first);

            vector<long long> visitedX;
            while (st != ed)
            {
                visitedX.push_back(*st);
                visitedHouseCount++;
                st++;
            }

            for (auto x : visitedX)
            {
                housesY[S.second].erase(x);
                housesX[x].erase(S.second);
            }
        }
        else
        {
            st = housesY[S.second].lower_bound(S.first);
            S.first += change;
            ed = housesY[S.second].upper_bound(S.first);

            vector<long long> visitedX;
            while (st != ed)
            {
                visitedX.push_back(*st);
                visitedHouseCount++;
                st++;
            }

            for (auto x : visitedX)
            {
                housesY[S.second].erase(x);
                housesX[x].erase(S.second);
            }
        }
    }

    cout << S.first << " " << S.second << " ";
    cout << visitedHouseCount << "\n";
}