#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll L[MAXN], A[MAXN], R[MAXN];
vector<ll> adj[MAXN];

void dfs(ll cur, ll p)
{
    ll sz, median;
    vector<ll> v;

    for(auto nxt : adj[cur])
    {
        v.push_back(A[nxt]);

        if(nxt != p)
        {
            dfs(nxt, cur);
            dp[cur][0] += min(dp[nxt][0], dp[nxt][1]);
            dp[cur][1] += dp[nxt][0];
        }
    }

    sz = v.size();
    sort(v.begin(), v.end());
    median = v[sz/2];

    if(median < L[cur])
        median = L[cur];
    if(median > R[cur])
        median = R[cur];

    for(auto nxt : adj[cur])
    {
        dp[cur][1] -= abs(A[cur] - A[nxt]);
        dp[cur][1] += abs(A[nxt] - median);
    }
}

void solve(int caseno)
{
    ll n, i, x, y, sum;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> L[i] >> A[i] >> R[i];
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }

    sum = 0;
    for(i = 1; i < n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        sum += abs(A[x] - A[y]);
    }

    dfs(1, 0);

    cout << sum + min(dp[0][0], dp[0][1]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}