#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

int leader[MAXN];
set<int> st[MAXN];
vector<int> adj[MAXN];
int arr[MAXN];
int Log[MAXN], sparse[MAXN][20];

int Find(int a)
{
    if(leader[a] == a)
        return a;
    else
        return Find(leader[a]);
}

void Union(int a, int b, int k)
{
    a = Find(a);
    b = Find(b);

    if(a == b)
        return;

    if(st[a].size() > st[b].size())
        swap(a, b);

    for(auto u : st[a])
    {
        if(st[b].find(u+1) != st[b].end())
            arr[u] = k;
        if(st[b].find(u-1) != st[b].end())
            arr[u-1] = k;
    }

    for(auto u : st[a])
        st[b].insert(u);

    leader[a] = b;
}

int getMin(int a, int b)
{
    if(a > b)
    return 0;

    int len = Log[b - a + 1];

    return max(sparse[a][len], sparse[b - (1<<len)+1][len]);
}

void solve(int caseno)
{
    int n, m, q, a, b, i, j;

    cin >> n >> m >> q;

    for(i = 1; i <= n; i++)
    {
        leader[i] = i;
        st[i].clear();
        st[i].insert(i);
        adj[i].clear();
        arr[i] = 0;
    }

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        Union(a, b, i);
    }

    // cout << "st:\n";
    // for(i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for(auto u : st[i])
    //         cout << u << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    for(i = 1; i < n; i++)
        sparse[i][0] = arr[i];

    for(j = 1; j < 20; j++)
    {
        for(i = 1; i + (1 << j) - 1 < n; i++)        
            sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);        
    }

    while(q--)
    {
        cin >> a >> b;

        cout << getMin(a, b-1) << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    for(int i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}