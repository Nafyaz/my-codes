#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll n, Time;
ll v[MAXN];
vector<ll> adj[MAXN];
ll bg[MAXN], ed[MAXN], tour[MAXN];
ll BIT[MAXN];

void Update(ll i, ll val)
{
    while(i <= n)
    {
        BIT[i] += val;
        i += i & (-i);
    }
}

ll Query(ll i)
{
    ll ret = 0;
    while(i > 0)
    {
        ret += BIT[i];
        i -= i & (-i);
    }

    return ret;
}

void dfs(ll cur, ll p)
{
    Time++;
    tour[Time] = cur;
    bg[cur] = Time;

    for(auto nxt : adj[cur])
    {
        if(nxt != p)
            dfs(nxt, cur);
    }

    ed[cur] = Time;
}

void solve(ll caseno)
{
    ll q, i, a, b, type, s, x;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
        cin >> v[i];

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Time = 0;
    dfs(1, -1);

    for(i = 1; i <= n; i++)
        Update(bg[i], v[i]);

    while(q--)
    {        
        cin >> type;
        if(type == 1)
        {
            cin >> s >> x;
            Update(bg[s], x - v[s]);
            v[s] = x;
        }
        else
        {
            cin >> s;
            cout << Query(ed[s]) - Query(bg[s]-1) << "\n";
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