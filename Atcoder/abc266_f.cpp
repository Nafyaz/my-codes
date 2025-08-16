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

bool isCycle[MAXN], vis[MAXN];
vector<int> adj[MAXN];
int nearestCycle[MAXN];

int findCycle(int node, int p)
{
    if(vis[node])
    {
        isCycle[node] = 1;
        return node;
    }

    vis[node] = 1;

    for(auto nxt : adj[node])
    {
        if(nxt == p)
            continue;

        int cycleStart = findCycle(nxt, node);

        if(cycleStart != 0)
        {
            isCycle[node] = 1;

            if(cycleStart == node)
                return 0;
            else
                return cycleStart;
        }
    }

    return 0;
}

void getNearest(int node, int p, int nearest)
{
    nearestCycle[node] = nearest;

    for(auto nxt : adj[node])
    {
        if(nxt == p || isCycle[nxt] == 1)
            continue;

        getNearest(nxt, node, nearest);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, q, a, b;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findCycle(1, 0);

    for(i = 1; i <= n; i++)
    {
        if(isCycle[i])
            getNearest(i, 0, i);
    }

    cin >> q;

    while(q--)
    {
        cin >> a >> b;

        if(nearestCycle[a] != nearestCycle[b])
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}