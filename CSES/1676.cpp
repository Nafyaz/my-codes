#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll root[MAXN], sz[MAXN];

ll Find(ll x)
{
    if(x == root[x])
        return x;
    
    return root[x] = Find(root[x]);
}

bool Union(ll x, ll y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
        return 0;
    
    if(sz[x] > sz[y])
        swap(x, y);
    
    root[x] = y;
    sz[y] += sz[x];

    return 1;
}

void solve(ll caseno)
{
    ll n, m, i, a, b, comp, mx;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        root[i] = i;
        sz[i] = 1;
    }

    comp = n;
    mx = 1;
    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;

        if(Union(a, b))
        {
            comp --;
            mx = max(mx, sz[root[a]]);
            mx = max(mx, sz[root[b]]);
        }

        cout << comp << " " << mx << "\n";
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