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

string s, t;

int bfs()
{
    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({s, 0});
    visited.insert(s);

    while (!q.empty())
    {
        pair<string, int> node = q.front();
        q.pop();

        if (node.first == t)
            return node.second;

        // cout << node.first << "\n";

        int dotIdx = -1;
        for (int i = 0; i < node.first.size(); i++)
        {
            if (node.first[i] == '.')
            {
                dotIdx = i;
                break;
            }
        }

        for (int i = 0; i < node.first.size() - 1; i++)
        {
            if (i >= dotIdx - 1 && i <= dotIdx + 1)
                continue;

            pair<string, int> child = node;
            swap(child.first[i], child.first[dotIdx]);
            swap(child.first[i + 1], child.first[dotIdx + 1]);
            child.second++;

            if (visited.find(child.first) == visited.end())
            {
                q.push(child);
                visited.insert(child.first);
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n >> s >> t;

    s.push_back('.');
    s.push_back('.');
    t.push_back('.');
    t.push_back('.');

    cout << bfs() << "\n";
}