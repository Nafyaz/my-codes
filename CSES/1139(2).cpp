#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll n, idx;
ll tour[maxN], lEnd[maxN];
ll colors[maxN], ans[maxN];
vector<ll> adj[maxN];

ll BIT[maxN];

void Update(ll i, ll d)
{
    while(i <= n)
    {
        BIT[i] += d;
        i += i & (-i);
    }
}

ll Query(ll i)
{
    ll sum = 0;
    while(i > 0)
    {
        sum += BIT[i];
        i -= i & (-i);
    }
    
    return sum;
}

void dfs(ll node, ll p = -1)
{
    lEnd[node] = idx;

    for(auto u : adj[node])
    {
        if(u != p)
            dfs(u, node);
    }

    show(node);
    show(idx);
    cout << "\n";

    tour[idx] = node;
    idx++;
}

void solve(ll caseno)
{
    ll i, a, b;

    cin >> n;
    
    for(i = 1; i <= n; i++)
    {
        cin >> colors[i];
        BIT[i] = 0;
        adj[i].clear();
    }

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    idx = 0;
    dfs(1);

    map<ll, ll> last;
    for (i = 0; i < n; i++) 
    {
		if (last.find(color[tour[i]]) != last.end())
			Update(last[color[tour[i]]], -1); 

		last[color[tour[i]]] = i; 
		Update(i, 1); 
		
		ans[tour[i]] = Query(i) - Query(lEnd[tour[i]] - 1);
	}

    // cout << "lEnd:\n";
    // for(i = 1; i <= n; i++)
    //     cout << i << ": " << lEnd[i] << "\n";
    // cout << "\n";

    // cout << "tour:\n";
    // for(i = 0; i < n; i++)
    //     cout << i << ": " << tour[i] << "\n";
    // cout << "\n";



    // for(i = 1; i <= n; i++)
    //     cout << ans[i] << " ";
    // cout << "\n";
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