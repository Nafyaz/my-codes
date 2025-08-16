#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

vector<int> adj[MAXN];
int sz[MAXN];

void dfs(int v)
{
    for (auto u : adj[v])
    {
        dfs(u);
        sz[v] += sz[u] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, x;

    cin >> n;

    for(i = 2; i <= n; i++)
    {
        cin >> x;

        adj[x].push_back(i);
    }

    dfs(1);

    for(i = 1; i <= n; i++)
        cout << sz[i] << " ";
    cout << "\n";
}