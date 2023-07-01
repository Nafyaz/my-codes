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
#define MAXN 100005

LL c[MAXN], ans[MAXN];
map<LL, LL> cnt[MAXN], sum[MAXN];
vector<LL> adj[MAXN];

void Merge(LL a, LL b)
{
    for(auto [x, y] : cnt[b])
    {
        sum[a][cnt[a][x]] -= x;
        cnt[a][x] += y;
        sum[a][cnt[a][x]] += x; 
    }
}

void dfs(LL node, LL p)
{
    cnt[node][c[node]] = 1;
    sum[node][1] = c[node];

    for(auto nxt : adj[node])
    {
        if(nxt == p)
            continue;

        dfs(nxt, node);

        if(cnt[node].size() < cnt[nxt].size())
        {
            swap(cnt[node], cnt[nxt]);
            swap(sum[node], sum[nxt]);
        }

        Merge(node, nxt);
    }

    // cout << node << "\ncnt:\n";
    // for(auto [x, y] : cnt[node])
    //     cout << x << " " << y << "; ";
    // cout << "\nsum:\n";
    // for(auto [x, y] : sum[node])
    //     cout << x << " " << y << "; ";
    // cout << "\n\n";

    ans[node] = (--sum[node].end()) -> ss;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, a, b;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> c[i];

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}