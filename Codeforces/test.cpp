#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int logn = 20;

vector <int> g[maxn];
int par[maxn];

int root(int x) {
    if(x == par[x]) return x;
    return par[x] = root(par[x]);
}
void join(int x, int y) {
    x = root(x);
    y = root(y);
    if(x != y) {
        par[x] = y;
    }
}
int anc[logn][maxn];
int dep[maxn];
int sub[maxn], res[maxn];

void dfs(int x, int dad) {
    anc[0][x] = dad;
    for(auto i : g[x]) {
        if(i != dad) {
            dep[i] = 1 + dep[x];
            dfs(i, x);
        }
    }
}

int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = logn - 1; i >= 0; i--) {
        if(dep[x] - (1 << i) >= dep[y]) x = anc[i][x];
    }
    if(x == y) return x;
    for(int i = logn - 1; i >= 0; i--) {
        if(anc[i][x] != anc[i][y]) {
            x = anc[i][x];
            y = anc[i][y];
        }
    }
    return anc[0][x];
}

int succ(int x, int y) {
    for(int i = logn - 1; i >= 0; i--) {
        if(dep[x] - (1 << i) > dep[y]) x = anc[i][x];
    }
    return x;
}

void add(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    
    sub[x] += 1;

    if(lca(x, y) == y) {
        sub[succ(x, y)] -= 1;
        sub[1] += 1;
    } else {
        sub[y] += 1;
    }
}

void finalize(int x, int dad, int tally) {
    res[x] = sub[x] + tally;
    for(auto i : g[x]) {
        if(i != dad) {
            finalize(i, x, tally + sub[x]);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    
    vector <pair <int, int>> bad;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if(root(x) != root(y)) {
            join(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
        } else {
            bad.emplace_back(x, y);
        }
    }
    dfs(1, 0);
    for(int i = 1; i < logn; i++) {
        for(int j = 1; j <= n; j++) {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    for(auto [x, y] : bad) add(x, y);
    finalize(1, 0, 0);
    
    string s (n, '0');
    for(int i = 1; i <= n; i++) {
        if(res[i] == bad.size()) s[i - 1] = '1';
    }
    cout << s << endl;
    return 0;
}
