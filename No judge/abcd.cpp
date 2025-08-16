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

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;

    int currX = 0, currY = 0;
    int dir = 0;
    int cnt = 0;
    vector<int> ret;
    while (l <= r && u <= d)
    {
        cout << currX << " " << currY << "\n";
        cnt++;
        if (cnt == 9)
        {
            cout << dir << "; " << l << " " << r << "; " << u << " " << d << "\n";
            return 0;
        }

        ret.push_back(matrix[currX][currY]);

        if (dir == 0)
        {
            if (currY == r)
            {
                dir = 1;
                u++;
                currX++;
            }
            else
            {
                currY++;
            }
        }
        else if (dir == 1)
        {
            if (currX == d)
            {
                dir = 2;
                r--;
                currY--;
            }
            else
            {
                currX++;
            }
        }
        else if (dir == 2)
        {
            if (currY == l)
            {
                dir = 3;
                d--;
                currX--;
            }
            else
            {
                currY--;
            }
        }
        else
        {
            if (currX == u)
            {
                dir = 0;
                l++;
                currY++;
            }
            else
            {
                currX--;
            }
        }
    }
}