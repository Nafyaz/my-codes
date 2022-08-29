#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int ans;
int a[MAXN];
vector<int> adj[MAXN];
set<int> st[MAXN];

void call(int node, int p)
{
    bool flag = 0;
    st[node].insert(a[node]);

    for(auto nxt : adj[node])
    {
        if(nxt == p)
            continue;

        a[nxt] ^= a[node];

        call(nxt, node);

        if(st[nxt].size() > st[node].size())
            swap(st[nxt], st[node]);

        for(auto u : st[nxt])
        {
            if(st[node].find(u ^ a[node] ^ a[p]) != st[node].end())
                flag = 1;

        }
        if(!flag)
        {
            for(auto u : st[nxt])
                st[node].insert(u);
        }
    }

    if(flag)
    {
        ans++;
        st[node].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, u, v;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    call(1, 0);

    cout << ans << "\n";
}