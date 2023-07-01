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
unordered_map<int, int> mp;
int ans[MAXN];
int Tree[4*MAXN];

void Update(int node, int bg, int ed, int idx, int val)
{
    if(bg == ed)
    {
        Tree[node] = 1;
        ans[idx] = val;

        return;
    }

    int leftNode = 2*node, rightNode = 2*node + 1;
    int mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

int Query(int node, int bg, int ed, int l, int r)
{
//    show(node);
//    show(bg);
//    show(ed);
//    show(l);
//    show(r);
//    cout << "\n";

    if(l > ed || r < bg)
        return 0;
    if(l <= bg && ed <= r)
        return Tree[node];

    int leftNode = 2*node, rightNode = 2*node + 1;
    int mid = (bg + ed)/2;

    return Query(leftNode, bg, mid, l, r) + Query(rightNode, mid+1, ed, l, r);
}

int getPos(int r)
{
    int low, high, mid, ret = 0;

    low = 1;
    high = r;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(Query(1, 1, n, mid, r) == r-mid+1)
            high = mid - 1;
        else
        {
            ret = mid;
            low = mid + 1;
        }
    }

//    show(r);
//    show(ret);
//    cout << "\n";

    return ret;
}

void solve(int caseno)
{
    int m, i, j, k, x, y, pos;

    cin >> n >> m;

//    Tree[1] = 1;
//    Tree[3] = 1;
//    cout << Query(1, 1, n, 1, 1) << "\n";

    mp.clear();
    for(i = 0; i < 4*n; i++)
        Tree[i] = 0;

    for(i = 0; i < m; i++)
    {
        cin >> x >> y;
        mp[x] = y;
    }

//    for(auto u : mp)
//        cout << u.ff << " " << u.ss << "; ";
//    cout << "\n";

    for(i = n; i >= 1; i--)
    {
        if(mp.find(i) == mp.end())
            pos = getPos(n);
        else
            pos = getPos(mp[i]);

//        show(i);
//        show(pos);
//        cout << "\n";

        if(pos == 0)
        {
            cout << "-1\n";
            return;
        }

        Update(1, 1, n, pos, i);

//        cout << "Tree:\n";
//        for(j = 1; j <= 5; j++)
//            cout << Tree[j] << " ";
//        cout << "\n";
    }

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
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

/*
1
3 2
2 1
1 2
*/

/*
1
4 1
2 3
*/
