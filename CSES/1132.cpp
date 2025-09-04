#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

vector<int> adj[MAXN];
int dist[MAXN][2];

pair<int, int> dfs1(int node, int par) {
    pair<int, int> ret = {node, 0};

    for (auto u : adj[node]) {
        if (u == par)
            continue;

        pair<int, int> p = dfs1(u, node);
        if (p.second >= ret.second) {
            ret = p;
            ret.second++;
        }
    }

    return ret;
}

void dfs2(int node, int par, int d, int direction) {
    dist[node][direction] = d;

    for (auto u : adj[node]) {
        if (u == par)
            continue;

        dfs2(u, node, d+1, direction);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int, int> p1 = dfs1(1, -1);
    pair<int, int> p2 = dfs1(p1.first, -1);

    dfs2(p1.first, -1, 0, 0);
    dfs2(p2.first, -1, 0, 1);

    // cout << p1.first << " " << p2.first << "\n";

    for (int i = 1; i <= n; i++)
        // cout << dist[i][0] << " " << dist[i][1] << "\n";
        cout << max(dist[i][0], dist[i][1]) << " ";
    cout << "\n";
}