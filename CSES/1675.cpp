#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

vector<pair<ll, pll>> edges;
ll root[MAXN];

ll Find(ll x)
{
    if(root[x] == x)
        return x;
    return root[x] = Find(root[x]);
}

void Union(ll x, ll y)
{
    x = Find(x);
    y = Find(y);

    root[max(x, y)] = min(x, y);
}

void solve(ll caseno)
{
    ll n, m, i, a, b, c, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
        root[i] = i;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;

        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    ans = 0;
    for(auto [c, nodes] : edges)
    {
        auto [a, b] = nodes;
        if(Find(a) != Find(b))
        {
            Union(a, b);
            ans += c;
        }
    }

    for(i = 1; i <= n; i++)
    {
        if(Find(i) != 1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

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