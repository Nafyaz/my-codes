#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const LL N = 1e6 + 7;
typedef pair<int,int> PII;

bool vis[N], ache[N];
int ID[N], in[N], out[N];

vector<int> adj[N], adjr[N];
vector<int> order, component;

// tp = 0 ,finding topo order
// tp = 1 , reverse edge traversal
//
void dfs(int u, int tp = 0) {
    vis[u] = true;
    if (tp) component.push_back(u);
    auto& ad = (tp ? adjr : adj);
    for (int v : ad[u])
        if (!vis[v]) dfs(v, tp);
    if (!tp) order.push_back(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<PII> edges;
    while (m--) {
        int u, v;
        cin >> u >> v;
        ache[u] = ache[v] = true;
        edges.push_back(PII(u,v));
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if(!ache[i]) continue;
        if (!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof vis);
    reverse(order.begin(), order.end());

    int cnt = 0;
    for (int i : order) {
        if(!ache[i]) continue;
        if (!vis[i]) {
            // one component is found
            dfs(i, 1);
            cnt++;
            for(int e : component) ID[e] = cnt;
            component.clear();
        }
    }
    for(auto[u,v] : edges){
        if(ID[u]==ID[v]) continue;
        in[ID[v]]++;
        out[ID[u]]++;
    }

    if(cnt==1) {
        cout<<0<<endl;
        return 0;
    }
    int zeroout = 0, zeroin = 0;
    for(int i=1; i<=cnt; i++){
        if(in[i]==0) zeroin++;
        if(out[i]==0) zeroout ++;
    }
    cout << max(zeroout, zeroin)<<endl;
}