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

int arr[MAXN];
vector<int> adj[MAXN];

void solve(int caseno)
{
    int n, m, i, x, y, cur, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        adj[i].clear();
    }

    for(i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(m%2 == 0)
    {
        cout << "0\n";
        return;
    }

//    for(i = 1; i <= n; i++)
//    {
//        cout << i << ": ";
//        for(auto u : adj[i])
//            cout << u << " ";
//        cout << "\n";
//    }

    ans = INT_MAX;
    for(cur = 1; cur <= n; cur++)
    {
//        show(i);
//        show(ans);
        if(adj[cur].size()%2 == 1)
            ans = min(ans, arr[cur]);

        for(auto nxt : adj[cur])
        {
            if(adj[cur].size()%2 == 0 && adj[nxt].size()%2 == 0)
                ans = min(ans, arr[cur]+arr[nxt]);
        }

    }

//    show(ans);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
/*
1
3 1
2 1 3
1 3
*/
