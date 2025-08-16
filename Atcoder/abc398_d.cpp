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

pair<int, int> operator-(const pair<int, int> a, const pair<int, int> b)
{
    return {a.first - b.first, a.second - b.second};
}

pair<int, int> operator+(const pair<int, int> a, const pair<int, int> b)
{
    return {a.first + b.first, a.second + b.second};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    pair<int, int> person;

    cin >> n >> person.first >> person.second;

    string s;
    cin >> s;

    set<pair<int, int>> smokes;
    pair<int, int> currPos = {0, 0};
    smokes.insert(currPos);
    for (auto c : s)
    {
        pair<int, int> newPos = currPos;

        if (c == 'N')
        {
            newPos.first--;
        }
        else if (c == 'W')
        {
            newPos.second--;
        }
        else if (c == 'S')
        {
            newPos.first++;
        }
        else if (c == 'E')
        {
            newPos.second++;
        }

        pair<int, int> diff = newPos - person;
        cout << (smokes.find(diff) == smokes.end() ? "0" : "1");
        // cout << c << ": ";
        // for (auto [r, c] : smokes)
        // {
        //     cout << r << " " << c << "; ";
        // }
        // cout << "\n";

        currPos = newPos;
        smokes.insert(currPos);
    }
}