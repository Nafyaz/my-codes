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
#define MAXN 1000006

vector<pLL> factor[MAXN];

LL a[MAXN], ans[MAXN];
vector<LL> adj[MAXN];

map<LL, LL> dfs(LL node, LL p)
{
    map<LL, LL> ret;

    ans[node] = 1;
    for(auto [p, cnt] : factor[a[node]])
    {
        ret[p] = cnt;
        ans[node] = (ans[node] * (cnt + 1)) % MOD;
    }
        

    for(auto nxt : adj[node])
    {
        if(nxt == p)
            continue;

        map<LL, LL> temp = dfs(nxt, node);

        if(temp.size() > ret.size())
            swap(temp, ret);

        for(auto [p, cnt] : temp)
        {
            ret[p] += cnt;
    }

    for(auto [p, cnt] : ret)
        ans[node] = (ans[node] * (cnt + 1)) % MOD;

    return ret;
}

void solve(int caseno)
{
    LL n, i, u, v;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        adj[i].clear();
    }

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL T = 1, caseno = 0, i, j, temp, cnt;

    for(i = 2; i < MAXN; i++)
    {
        if(factor[i].empty())
        {
            for(j = i; j < MAXN; j += i)
            {
                temp = j;

                for(cnt = 0; temp % i == 0; temp /= i)
                    cnt++;

                factor[j].push_back({i, cnt});
            }
        }
    }

    // for(i = 1; i <= 10; i++)
    // {
    //     show(i);
    //     for(auto u : factor[i])
    //         cout << u.ff << " " << u.ss << "; ";
    //     cout << "\n";
    // }

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}