#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll colors[maxN], ans[maxN];
vector<ll> adj[maxN];

void dfs(ll node, ll p, set<ll> &st)
{
    st.insert(colors[node]);

    if(adj[node].size() == 1 && p != -1)
    {
        ans[node] = 1;
        return;
    }

    for(auto u : adj[node])
    {
        if(u != p)
        {
            set<ll> st2;
            dfs(u, node, st2);

            if(st.size() < st2.size())
                swap(st, st2);
            
            for(auto v: st2)
                st.insert(v);
        }
    }

    // show(node);
    // for(auto u : st)
    //     cout << u << " ";
    // cout << "\n";

    ans[node] = st.size();
}

void solve(ll caseno)
{
    ll n, i, a, b;

    cin >> n;
    
    for(i = 1; i <= n; i++)
        cin >> colors[i];

    // for(i = 1; i <= n; i++)
    //     cout << colors[i] << " ";
    // cout << "\n";

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // for(i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for(auto u : adj[i])
    //         cout << u << " ";
    //     cout << "\n";
    // }

    set<ll> st;
    dfs(1, -1, st);

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
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