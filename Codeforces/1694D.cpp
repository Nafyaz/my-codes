#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll parent[MAXN];
vector<ll> adj[MAXN];
ll L[MAXN], R[MAXN], a[MAXN];

ll idx;
ll tour[MAXN];

void createTourTree(ll node)
{
    for(auto u : adj[node])
        createTourTree(u);

    tour[idx] = node;
    idx++;
}

void solve(ll caseno)
{
    ll n, i, j, ans, mnA, node;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        parent[i] = -1;
        adj[i].clear();
        a[i] = 0;
    }

    for(i = 2; i <= n; i++)
    {
        cin >> parent[i];
        adj[parent[i]].push_back(i);
    }

    for(i = 1; i <= n; i++)    
        cin >> L[i] >> R[i];
    
    idx = 0;
    createTourTree(1);

    ans = 0;
    for(i = 0; i < n; i++)
    {        
        node = tour[i];

        // show(i);
        // show(node);
        // cout << "\n";
        // for(j = 1; j <= n; j++)
        //     cout << a[j] << " ";
        // cout << "\n";

        if(L[node] <= a[node] && a[node] <= R[node])
            continue;

        ans++;
        mnA = INT_MAX;
        for(j = node; j != -1 && mnA > 0; j = parent[j])
        {
            mnA = min(mnA, R[j] - a[j]);
            a[j] += mnA;
        }
    }

    cout << ans << "\n";
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