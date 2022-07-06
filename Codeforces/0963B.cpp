#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

queue<int> ans;
vector<int> adj[MAXN];
int degree[MAXN] = {0};
bool deleted[MAXN] = {0};

void del(int cur, int p)
{
    if(deleted[cur] || degree[cur] % 2)
        return;

    for(auto nxt : adj[cur])
    {
        if(degree[nxt])
            degree[nxt]--;
    }

    deleted[cur] = 1;
    degree[cur] = 0;
    ans.push(cur);

    for(auto nxt : adj[cur])    
    {
        if(nxt != p)
            del(nxt, cur);
    }
}

void dfs(int cur, int p)
{
    for(auto nxt : adj[cur])
    {
        if(nxt != p)
            dfs(nxt, cur);
    }

    del(cur, p);
}

void solve(int caseno)
{
    int n, i, p, cur;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> p;

        if(p != 0)
        {
            adj[i].push_back(p);
            adj[p].push_back(i);

            degree[i]++;
            degree[p]++;
        }
    }

    if(n%2 == 0)
    {
        cout << "NO\n";
        return;
    }

    dfs(1, 0);

    cout << "YES\n";
    while(!ans.empty())
    {
        cout << ans.front() << "\n";
        ans.pop();
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
/*
5
0 1 1 3 2
*/