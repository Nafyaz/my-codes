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

int getHash(string x)
{
    int ret = 0;

    for (int i = 0; i < x.size(); i++)
    {
        ret *= 3;

        if (x[i] == 'W')
            ret += 1;
        else if (x[i] == 'B')
            ret += 2;
    }

    return ret;
}

int getDotIdx(string x)
{
    int dotIdx = -1;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '.')
            return i;
    }
}

int bfs()
{
    queue<pair<string, int>> qS, qT;
    unordered_map<int, int> distS, distT;

    qS.push({s, 0});
    distS[getHash(s)] = 0;

    qT.push({t, 0});
    distT[getHash(t)] = 0;

    while (!qS.empty() && !qT.empty())
    {
        pair<string, int> nodeS = qS.front();
        qS.pop();

        pair<string, int> nodeT = qT.front();
        qT.pop();

        // cout << "|" << nodeS.first << "| |" << nodeT.first << "|\n";

        int dotIdxS = getDotIdx(nodeS.first), dotIdxT = getDotIdx(nodeT.first);

        for (int i = 0; i < nodeS.first.size() - 1; i++)
        {
            if (i >= dotIdxS - 1 && i <= dotIdxS + 2)
                continue;

            pair<string, int> child = nodeS;
            swap(child.first[i], child.first[dotIdxS]);
            swap(child.first[i + 1], child.first[dotIdxS + 1]);
            child.second++;

            if (child.first == t)
                return child.second;

            int hash = getHash(child.first);

            if (distT.find(hash) != distT.end())
            {

                return child.second + distT[hash];
            }

            if (distS.find(hash) == distS.end())
            {
                qS.push(child);
                distS[hash] = child.second + 1;
            }
        }

        for (int i = 0; i < nodeT.first.size(); i++)
        {
            if (i >= dotIdxT - 1 && i <= dotIdxT + 2)
                continue;

            pair<string, int> child = nodeT;
            swap(child.first[i], child.first[dotIdxT]);
            swap(child.first[i + 1], child.first[dotIdxT + 1]);
            child.second++;

            if (child.first == s)
                return child.second;

            int hash = getHash(child.first);

            if (distS.find(hash) != distS.end())
                return child.second + distS[hash];

            if (distT.find(hash) == distT.end())
            {
                qT.push(child);
                distT[hash] = child.second + 1;
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

    int wCount = 0, bCount = 0;
    for (int i = 0; i < n; i++)
    {
        wCount += (s[i] == 'W');
        wCount -= (t[i] == 'W');

        bCount += (s[i] == 'b');
        bCount -= (t[i] == 'b');
    }

    if (wCount || bCount)
    {
        cout << -1 << "\n";
        return 0;
    }

    s.push_back('.');
    s.push_back('.');
    t.push_back('.');
    t.push_back('.');

    cout << bfs() << "\n";
}