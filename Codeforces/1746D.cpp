#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 200005

LL s[MAXN];
LL worst[MAXN];
vector<LL> adj[MAXN];

LL dfs(LL node, LL prev, LL k)
{
    LL curr = prev + s[node];
    if(adj[node].size() == 0)
    {
        worst[node] = curr;
        return curr*k;
    }

    LL i, ret = 0, n = adj[node].size();
    vector<LL> w;

    for(auto nxt : adj[node])
    {
        ret += dfs(nxt, curr, (k+n-1)/n);
        w.push_back(worst[nxt]);
    }

    sort(w.begin(), w.end(), greater<LL>());

    if(k%n)
    {
        for(i = k%n; i < n; i++)
            ret -= w[i];
        worst[node] = w[k%n - 1];
    }
    else
        worst[node] = w[n-1];

    return ret;
}

void solve(int caseno)
{
    LL n, k, i, p;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
        adj[i].clear();

    for(i = 2; i <= n; i++)
    {
        cin >> p;

        adj[p].push_back(i);
    }

    for(i = 1; i <= n; i++)
        cin >> s[i];

    cout << dfs(1, 0, k) << "\n";
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