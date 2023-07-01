#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<ll> adj[MAXN];
ll parent[MAXN], dist[MAXN];

void bfs()
{
    ll cur, nxt;
    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(dist[nxt] == -1)
            {
                parent[nxt] = cur;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

void solve(ll caseno)
{
    ll n, m, i, cur, a, b;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dist, -1, sizeof dist);
    bfs();

    if(dist[n] == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        stack<ll> stk;
        for(cur = n; cur != 0; cur = parent[cur])        
            stk.push(cur);

        cout << stk.size() << "\n";   
        while(!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}