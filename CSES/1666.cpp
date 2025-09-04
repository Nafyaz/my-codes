#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

bool visited[MAXN];
vector<int> adj[MAXN];

void dfs(int node) {
    visited[node] = true;

    for (auto u : adj[node]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);

            if (i > 1)
                ans.push_back({i-1, i});
        }
    }

    cout << ans.size() << "\n";
    for (auto& [u, v] : ans) {
        cout << u << " " << v << "\n";
    }
}