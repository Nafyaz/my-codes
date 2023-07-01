#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1003

vector<ll> adj[2][MAXN];
set<ll> st[2][MAXN];

void dfs(ll id, ll cur, ll p, ll step)
{
    if(st[id][cur].find(step) != st[id][cur].end())
        return;
    
    st[id][cur].insert(step);

    for(auto nxt : adj[id][cur])
    {
        if(nxt != p)        
            dfs(id, nxt, cur, step + 1);        
    }
}

void solve(ll caseno)
{
    ll n1, n2, m1, m2;
    ll i, a, b, Q, q;
    bool flag;
    
    cin >> n1 >> n2;
    cin >> m1 >> m2;

    for(i = 1; i <= m1; i++)
    {
        cin >> a >> b;
        adj[0][a].push_back(b);
    }
    dfs(0, 1, -1, 0);

    for(i = 1; i <= m2; i++)
    {
        cin >> a >> b;
        adj[1][a].push_back(b);
    }
    dfs(1, 1, -1, 0);

    cin >> Q;
    while(Q--)
    {
        cin >> q;

        flag = 0;
        for(auto u : st[0][n1])
        {
            if(st[1][n2].find(q - u) != st[1][n2].end())
                flag = 1;
        }

        cout << (flag? "Yes" : "No") << "\n";
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