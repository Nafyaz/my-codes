#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll n, m;
vector<ll> rev[MAXN];
ll dist[MAXN], out[MAXN];

void solve(ll caseno)
{
    ll u, v, i, d, cur, nxt, nd;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        rev[i].clear();
        out[i] = 0;
        dist[i] = INT_MAX;
    }

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;
        out[u]++;
        rev[v].push_back(u);
    }

    set<pll> st;

    dist[n] = 0;
    st.insert({0, N});

    while(!st.empty())
    {
        auto [d, cur] = *st.begin();
        st.erase(st.begin());

        if(d != dist[cur])
            continue;

        for(auto nxt : rev[cur])
        {
            out[nxt]--;
            nd = d + 1 + outDeg[nxt];
			if (dist[nxt] == -1 || nd < dist[nxt])
			{
                dist[nxt] = nd;
                st.insert({nd, nxt});
            }
        }
    }

    cout << dist[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}