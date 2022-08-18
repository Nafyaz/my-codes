#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

int n;
vector<int> adj[MAXN];
int parent[MAXN], level[MAXN], anc[MAXN][21];

void dfs(int cur, int p, int l)
{
    parent[cur] = p;
    level[cur] = l;

    for(auto nxt : adj[cur])
    {
        if(nxt != parent[cur])
            dfs(nxt, cur, l+1);
    }
}

void LCA_init()
{
    dfs(1, 1, 0);

    int i, j;
    for(i = 1; i <= n; i++)
        anc[i][0] = parent[i];

    for(j = 1; j < 21; j++)
    {
        for(i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

int getLCA(int u, int v)
{
    if(level[u] < level[v])
        swap(u, v);

    int i;
    for(i = 20; i >= 0; i--)
    {
        if(level[anc[u][i]] >= level[v])
            u = anc[u][i];
    }

    if(u == v)
        return u;

    for(i = 20; i >= 0; i--)
    {
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return parent[u];
}


void solve(int caseno)
{
    int i, j, k, a, b, l, ans, prev, dist;

    cin >> n;

    for(i = 1; i <= n; i++)
        adj[i].clear();

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LCA_init();

    ans = 1;
    prev = -1;
    for(i = 1; i <= n; i++)
    {
        cin >> a;

        if(prev != -1)
        {
            l = getLCA(prev, a);

            dist = level[prev] + level[a] - 2*level[l];

            if(dist > 3)
                ans = 0;
        }

        prev = a;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

