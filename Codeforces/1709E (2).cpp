#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int ans;
int a[MAXN], xr[MAXN];
vector<int> adj[MAXN];
set<int> st[MAXN];

int dfs(int node, int p)
{
    int ret, bigChild, sz;

    ret = bigChild = sz = 0;

    xr[node] = a[node] ^ a[p];

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, u, v;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans << "\n";
}