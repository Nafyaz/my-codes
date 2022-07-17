#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

int n;
int L[MAXN], freq[MAXN][102];
vector<int> adj[MAXN];
int parent[MAXN], anc[MAXN][21];
int level[MAXN];

void dfs(int cur, int p)
{
    parent[cur] = p;
    level[cur] = level[p] + 1;

    int i;
    for(i = 1; i <= 100; i++)
        freq[cur][i] = freq[p][i] + (i == L[cur]);

    for(auto nxt : adj[cur])
    {
        if(nxt != p)
            dfs(nxt, cur);
    }
}

void LCA_init()
{
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

int countCells(set<int>& captives, int diff)
{
    int ret = 0, bg = -2*diff;
    for(auto c : captives)
    {
        if(c > bg + diff)
        {
            bg = c;
            ret++;
        }
    }

    return ret;
}

void solve(int caseno)
{
    int q, i, x, y, k, lca;
    int queryFreq, low, high, mid, ans;
    set<int> captives;

    cin >> n >> q;

    for(i = 1; i < n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i = 1; i <= n; i++)
        cin >> L[i];

    dfs(1, 1);
    LCA_init();

    while(q--)
    {
        cin >> x >> y >> k;

        lca = getLCA(x, y);

        captives.clear();
        for(i = 1; i <= 100; i++)
        {
            queryFreq = freq[x][i] + freq[y][i] - 2*freq[lca][i] + (i == L[lca]);
            if(queryFreq)
                captives.insert(i);
        }

        ans = 100;
        low = 0;
        high = 100;
        while(low <= high)
        {
            mid = (low + high)/2;

            if(countCells(captives, mid) > k)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        cout << ans << "%\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}