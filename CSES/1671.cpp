#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

vector<pll> adj[MAXN];
ll dist[MAXN];

void djikstra()
{
    ll cur, cd;

    set<pll> st;
    st.insert({0, 1});
    dist[1] = 0;

    while(!st.empty())
    {
        cd = (*st.begin()).ff;
        cur = (*st.begin()).ss;

        st.erase(st.begin());

        if(cd > dist[cur])
            continue;


        for(auto [nd, nxt] : adj[cur])
        {
            if(dist[nxt] > cd + nd)
            {
                st.insert({cd + nd, nxt});
                dist[nxt] = cd + nd;
            }
        }
    }
}

void solve(ll caseno)
{
    ll n, m, i, a, b, c;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    fill(dist+1, dist+n+1, 1e18);
    djikstra();

    for(i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}