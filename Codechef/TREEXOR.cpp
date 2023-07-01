#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 200005

int ones[MAXN];
bool val[MAXN];
vector<int> adj[MAXN];

int dfs(int cur, int rem)
{
//    show(cur);
//    show(rem);
//    cout << "\n";

    ones[cur] = 0;

    for(auto nxt : adj[cur])
    {
        rem = dfs(nxt, rem);
        ones[cur] += ones[nxt];
    }

    if(rem)
    {
        val[cur] = (ones[cur]%2 == 0? 1 : 0);
        ones[cur] += val[cur];
        rem--;
    }
    else
    {
        val[cur] = (ones[cur]%2 == 0? 0 : 1);
        ones[cur] += val[cur];
    }

    return rem;
}

void solve(int caseno)
{
    int n, k, i, p;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        val[i] = 0;
        adj[i].clear();
    }

    for(i = 2; i <= n; i++)
    {
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, k);

    for(i = 1; i <= n; i++)
        cout << val[i];
    cout << "\n";
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
