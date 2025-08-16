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

vector<int> adj[200005];
bool visited[200005];

int dfs(int node, int par, int taken)
{
    visited[node] = true;

    if (taken == 1 && adj[node].size() < 4)
        return 1;

    vector<int> nodeCount;
    for (auto u : adj[node])
    {
        if (u == par)
            continue;

        nodeCount.push_back(dfs(u, node, 1));
    }

    sort(nodeCount.begin(), nodeCount.end(), std::greater<>());

    if (taken == 0)
    {
        if (adj[node].size() < 4)
            return 1 + nodeCount[0];
        else
            return 1 + nodeCount[0] + nodeCount[1] + nodeCount[2] + nodeCount[3];
    }
    else
    {
        return 1 + nodeCount[0] + nodeCount[1] + nodeCount[2];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, b;

    cin >> n;

    vector<int> fourDegreeNodes;
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        if (adj[a].size() == 4)
            fourDegreeNodes.push_back(a);

        if (adj[b].size() == 4)
            fourDegreeNodes.push_back(b);
    }

    if (fourDegreeNodes.empty())
    {
        cout << "-1\n";
        return 0;
    }

    int ans = -1;
    for (auto node : fourDegreeNodes)
    {
        if (visited[node])
            continue;

        ans = max(ans, dfs(node, -1, 0));
    }

    cout << ans << "\n";
}