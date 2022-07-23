#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

int n;
vector<pii> adj[MAXN];
map<int, int> mp[MAXN];
int temp[MAXN], dist[MAXN];

void djikstra()
{
    multiset<pii> ms;

    ms.insert({0, 1});
    dist[1] = 0;

    while(!ms.empty())
    {
        int cd = (*ms.begin()).ff;
        int cur = (*ms.begin()).ss;
        ms.erase(ms.begin());

        if(cd > dist[cur])
            continue;

        if(mp[cur].find(cd) != mp[cur].end())
            cd += mp[cur][cd];

        for(auto node : adj[cur])
        {
            int nd = node.ff;
            int nxt = node.ss;

            if(dist[nxt] == -1 || dist[nxt] > cd + nd)
            {
                ms.insert({cd+nd, nxt});
                dist[nxt] = cd+nd;
            }
        }
    }
}

void solve(int caseno)
{
    int m, i, j, k, a, b, c;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    for(i = 1; i <= n; i++)
    {
        cin >> k;
        for(j = 0; j < k; j++)
            cin >> temp[j];

        for(j = k-1; j >= 0; j--)
        {
            if(mp[i].find(temp[j]+1) == mp[i].end())
                mp[i][temp[j]] = 1;
            else
                mp[i][temp[j]] = mp[i][temp[j] + 1] + 1;
        }
    }

    memset(dist, -1, sizeof dist);
    djikstra();

    cout << dist[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
