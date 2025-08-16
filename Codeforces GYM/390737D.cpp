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

int arr[MAXN];
int Tree[4*MAXN], Lazy[4*MAXN];

void updateRange(int node, int bg, int ed, int l, int r, int val)
{
    int leftNode = 2*node, rightNode = 2*node+1;
    int mid = (bg + ed) / 2;

    if(Lazy[node] != 0)
    {
        Tree[node] = __gcd(Tree[node], Lazy[node]);

        if(bg != ed)
        {
            Lazy[leftNode] = __gcd(Lazy[leftNode], Lazy[node]);
            Lazy[rightNode] = __gcd(Lazy[rightNode], Lazy[node]);
        }

        Lazy[node] = 0;
    }

    if(l > ed || r < bg)
        return;

    if(l <= bg && ed <= r)
    {
        Lazy[node] = val;
        return;
    }

    updateRange(leftNode, bg, mid, l, r, val);
    updateRange(rightNode, mid+1, ed, l, r, val);

    Tree[node] = __gcd(Tree[leftNode], Tree[rightNode]);
}

int query(int node, int bg, int ed, int idx)
{
    int leftNode = 2*node, rightNode = 2*node+1;
    int mid = (bg + ed) / 2;

    if(Lazy[node] != 0)
    {
        Tree[node] = __gcd(Tree[node], Lazy[node]);

        if(bg != ed)
        {
            Lazy[leftNode] = __gcd(Lazy[leftNode], Lazy[node]);
            Lazy[rightNode] = __gcd(Lazy[rightNode], Lazy[node]);
        }

        Lazy[node] = 0;
    }

    if(idx < bg || idx > ed)
        return 0;

    if(bg == idx && idx == ed)
        return Tree[node];

    return __gcd(query(leftNode, bg, mid, idx), query(rightNode, mid+1, ed, idx));
}

void solve(int caseno)
{
    int n, i, dist;

    cin >> n;

    for(i = 0; i < 4*n; i++)    
        Tree[i] = Lazy[i] = 0;    

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for(i = 0; i < n; i++)
    {
        dist = min(n-i-1, i);

        if(n-i-1 > dist)
            dist = 2*dist + 2;
        else
            dist = 2*dist + 1;

        // show(i);
        // show(arr[i]);
        // show(dist);
        // cout << "\n";
        
        updateRange(1, 1, n, 1, dist, arr[i]);
    }

    for(i = 1; i <= n; i++)
        cout << query(1, 1, n, i) << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}