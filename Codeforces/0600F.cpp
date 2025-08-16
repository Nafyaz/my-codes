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
#define MAXN 1003

int degrees[MAXN];
vector<pii> adj[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, mx;

    cin >> n >> m;

    mx = 0;
    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;

        adj[a].push_back({i, b});
        adj[b].push_back({i, a});

        degrees[a]++;
        if(a != b)
            degrees[b]++;

        mx = max(mx, degrees[a]);
        mx = max(mx, degrees[b]);
    }

    for(i = )
}