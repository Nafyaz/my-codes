#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

bool vis[MAXN], last[MAXN];
vector<int> adj[MAXN];
vector<int> cycle;

void dfs(int cur)
{
    vis[cur] = 1;
    cycle.push_back(cur);

    for(auto nxt : adj[cur])
    {
        if(!vis[nxt])
        {
            dfs(nxt);
            return;
        }
    }

    for(auto nxt : adj[cur])
        last[nxt] = 1;
}

void solve(int caseno)
{
    int n, m, k, i, a, b;

    cin >> n >> m >> k;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for(i = 0; i < cycle.size(); i++)
    {
        if(last[cycle[i]])
        {
            cout << cycle.size() - i << "\n";
            for(; i < cycle.size(); i++)
                cout << cycle[i] << " ";
            break;
        }
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