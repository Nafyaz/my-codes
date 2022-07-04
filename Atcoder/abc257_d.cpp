#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n;
ll x[202], y[202];
ll p[202];
bool vis[202];

vector<pll> adj[202];

void dfs(ll cur, ll s)
{
    // show(cur);
    vis[cur] = 1;

    ll nxt, d;

    for(auto u : adj[cur])
    {
        nxt = u.ss;
        d = u.ff;
        if(vis[nxt] == 0 && d <= s)
            dfs(nxt, s);
    }
}

bool isPossible(ll bg, ll s)
{
    memset(vis, 0, sizeof vis);
    dfs(bg, s);

    ll i;
    for(i = 0; i < n; i++)
    {
        if(vis[i] == 0)
            return 0;
    }

    return 1;
}

void solve(ll caseno)
{
    ll i, j, s, mxs, dist, low, high, mid, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> p[i];

    mxs = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i != j)
            {
                dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                s = (dist + p[i] - 1) / p[i];
                adj[i].push_back({s, j});
                mxs = max(mxs, s);

                s = (dist + p[j] - 1) / p[j];
                adj[j].push_back({s, i});
                mxs = max(mxs, s);
            }
        }
    }

    // cout << isPossible(1, 2) << "\n";

    ans = LLONG_MAX;
    for(i = 0; i < n; i++)
    {
        low = 0;
        high = mxs;
        while(low <= high)
        {
            mid = (low + high) / 2;

            if(isPossible(i, mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
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