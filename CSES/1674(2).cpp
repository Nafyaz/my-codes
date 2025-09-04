#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int sz[MAXN];
vector<int> adj[MAXN];

void dfs(int n) {
    for (auto u : adj[n]) {
        dfs(u);
        sz[n] += sz[u] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, p;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> p;

        adj[p].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << sz[i] << " ";
    
    cout << "\n";
}