#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

vector<ll> adj[MAXN];
ll parent[MAXN], sz[MAXN];
vector<ll> cnt, primes;

void dfs(ll cur, ll p)
{
    parent[cur] = p;
    sz[cur] = 1;

    for(auto nxt : adj[cur])
    {
        if(nxt != p)
        {
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
        }
    }
}

void solve(ll caseno)
{
    ll n, i, j, u, v, m, p, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
        adj[i].clear();
    cnt.clear();
    primes.clear();

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for(i = 2; i <= n; i++)
        cnt.push_back(sz[i] * (sz[1] - sz[i]));
    sort(cnt.begin(), cnt.end());

    cin >> m;

    for(i = 0; i < m; i++)
    {
        cin >> p;
        primes.push_back(p);
    }
    sort(primes.begin(), primes.end());

    while(primes.size() > cnt.size())
    {
        p = primes.back();
        primes.pop_back();
        primes.back() = (primes.back() * p) % MOD;
    }

    reverse(primes.begin(), primes.end());
    reverse(cnt.begin(), cnt.end());
    
    ans = 0;
    for(i = 0; i < cnt.size(); i++)
    {
        if(i < primes.size())
            ans = (ans + cnt[i]*primes[i]) % MOD;
        else
            ans = (ans + cnt[i]) % MOD;
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

/*
1
4
1 2
2 3
3 4
4
2 3 5 7
*/