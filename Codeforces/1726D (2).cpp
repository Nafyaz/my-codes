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

int leader[2][MAXN];
int parent[MAXN];
bool ans[MAXN];
map<pii, int> edges;
vector<int> adj[MAXN];

int Find(int color, int x)
{
    if(leader[color][x] == x)
        return x;

    return leader[color][x] = Find(color, leader[color][x]);
}

void Union(int color, int x, int y)
{
    x = Find(color, x);
    y = Find(color, y);

    if(x == y)
        return;
    
    leader[color][max(x, y)] = min(x, y);
}

void dfs(int node, int p)
{
    parent[node] = p;
    for(auto nxt : adj[node])
    {
        if(nxt == p)
            continue;

        dfs(nxt, node);
    }
}

void solve(int caseno)
{
    int n, m, a, b, a2, b2, i;

    cin >> n >> m;

    edges.clear();
    for(i = 1; i <= n; i++)
    {
        leader[0][i] = leader[1][i] = i;
        adj[i].clear();
    }

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        if(a > b)
            swap(a, b);

        edges[{a, b}] = i;


        if(Find(0, a) != Find(0, b))
        {
            Union(0, a, b);

            adj[a].push_back(b);
            adj[b].push_back(a);

            ans[i] = 0;
        }
        else if(Find(1, a) != Find(1, b))
        {
            Union(1, a, b);
            ans[i] = 1;
        }
        else
        {
            dfs(a, 0);
            
            a2 = parent[b];
            b2 = b;

            if(a2 > b2)
                swap(a2, b2);

            swap(ans[edges[{a, b}]], ans[edges[{a2, b2}]]);
        }
    }

    for(i = 0; i < m; i++)
        cout << ans[i];
    cout << "\n";
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