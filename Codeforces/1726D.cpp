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

int leader[MAXN];
int parent[MAXN];
bool ans[MAXN];
vector<int> adj[MAXN];

int Find(int x)
{
    if(leader[x] == x)
        return x;

    return leader[x] = Find(leader[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;
    
    leader[max(x, y)] = min(x, y);
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
    int n, m, a, b, i, j, a2, b2;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        adj[i].clear();
        leader[i] = i;
    }

    map<pii, int> edgeId;
    vector<pii> rem;
    string ans(m, '0');

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        if(a > b)
            swap(a, b);
        
        edgeId[{a, b}] = i;

        if(Find(a) != Find(b))
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
            Union(a, b);
        }
        else
        {
            rem.push_back({a, b});
            ans[i] = '1';
        }
    }

    if(rem.size() < 3)
    {
        cout << ans << "\n";
        return;
    }

    set<int> cont;
    for(auto [x, y] : rem)
    {
        cont.insert(x);
        cont.insert(y);
    }

    if(cont.size() == 3)
    {
        a = rem[0].ff;
        b = rem[0].ss;

        dfs(a, -1);

        a2 = parent[b];
        b2 = b;
        
        if(a2 > b2)
            swap(a2, b2);

        swap(ans[edgeId[{a2, b2}]], ans[edgeId[{a, b}]]);
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