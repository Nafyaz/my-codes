#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int arr[MAXN];
int Tree[4*MAXN];
vector<int> L[MAXN], R[MAXN];

int ans[MAXN];

void Update(int node, int bg, int ed, int idx, int val)
{
    if(bg == ed)
    {
        Tree[node] = val;
        arr[idx] = val;
        return;
    }

    int leftNode = 2*node, rightNode = 2*node + 1;
    int mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = min(Tree[leftNode], Tree[rightNode]);
}

int Query(int node, int bg, int ed, int l, int r)
{
    if(bg > r || ed < l)
        return 0;

    if(l <= bg && ed <= r)
        return Tree[node];

    int leftNode = 2*node, rightNode = 2*node + 1;
    int mid = (bg + ed)/2;

    int p1 = Query(leftNode, bg, mid, l, r);
    int p2 = Query(rightNode, mid+1, ed, l, r);

    return min(p1, p2);
}

void solve(int caseno)
{
    int n, m, i, temp, totalL, bg, ed;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> temp;
        L[temp].push_back(i);

        cin >> temp;
        R[temp].push_back(i);
    }

    totalL = 0;
    for(i = 1; i <= m; i++)
    {
        totalL += L[i].size();

        for(auto u : L[i])        
        {
            arr[u] = max(arr[u], i);
            Update(1, 1, n, u, arr[u]);
        }
        for(auto u : R[i])
        {
            arr[u] = max(arr[u], i);
            Update(1, 1, n, u, arr[u]);
        }

        if(totalL == n)        
        {
            bg = i - Query(1, 1, n, 1, n) + 1;
            ed = i;
            
            ans[bg] += 1;
            ans[ed+1] -= 1;
        }
    }

    for(i = 1; i <= m; i++)
    {
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}