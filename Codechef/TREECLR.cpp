#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

vector<LL> adj[MAXN];

LL c;
LL dfs(LL node, LL p, LL minus)
{
    LL ret = c - minus, j;

    if(minus == 0)
        j = 1;
    else
        j = 2;

    for(LL i = 0; i < adj[node].size(); i++)
    {
        if(adj[node][i] == p)
            continue;

        ret = (ret * dfs(adj[node][i], node, j))%MOD;
        j++;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, u, v;

    cin >> n >> c;

    for(i = 1; i < n; i++)    
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << dfs(1, 0, 0) << "\n";
}