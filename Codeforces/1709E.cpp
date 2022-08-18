#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll n, ans;
ll a[MAXN];
vector<ll> adj[MAXN];
ll parent[MAXN];
set<ll> st[MAXN];

void dfs(ll node, ll p)
{
    bool flag;
    st[node].insert(a[node]);

    flag = 1;
    for(auto nxt : adj[node])
    {
        if(nxt == p)
            continue;

        if(flag == 0)
        {
            st[nxt].clear();
            continue;
        }

        dfs(nxt, node);

        for(auto u : st[nxt])
        {
            if(st[node].find(u) != st[node].end())
            {
                flag = 0;
                break;
            }

            st[node].insert(u^a[node]);
        }

        st[nxt].clear();

        if(flag == 0)
        {
            // show(node);
            ans++;
            st[node].clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, x, y;

    cin >> n; 

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i < n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 1);

    cout << ans << "\n";
}