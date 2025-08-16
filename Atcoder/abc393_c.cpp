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

unordered_set<int> adj[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, u, v;

    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;

        if (u == v || adj[u].find(v) != adj[u].end())
            ans++;
        else
        {
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }

    cout << ans << "\n";
}