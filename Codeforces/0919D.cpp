#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

string s;
vector<ll> adj[MAXN];
ll color[MAXN], ans;
ll dp[MAXN][26];
bool hasCycle;

void dfs(ll cur)
{
    ll j;
    color[cur] = 1;

    for(auto nxt : adj[cur])
    {                
        if(hasCycle || color[nxt] == 1)
        {
            hasCycle = 1;
            return;
        }

        if(color[nxt] == 0)
            dfs(nxt);

        for(j = 0; j < 26; j++)        
            dp[cur][j] = max(dp[cur][j], dp[nxt][j]);  
    }

    color[cur] = 2;

    dp[cur][s[cur-1] - 'a']++;
    ans = max(ans, dp[cur][s[cur-1] - 'a']);
}

void solve(ll caseno)
{
    ll n, m, i, a, b;
    bool flag;

    cin >> n >> m >> s;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
    }

    ans = hasCycle = 0;
    for(i = 1; i <= n; i++)
    {
        if(color[i] == 0)
            dfs(i);      
    }

    if(hasCycle)
        cout << "-1\n";
    else
        cout << ans << "\n";
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