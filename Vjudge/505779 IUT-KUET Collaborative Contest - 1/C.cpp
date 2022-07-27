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

ll h[MAXN], hSorted[MAXN], steps[MAXN];
map<pll, ll> hSortedRev;
ll Tree[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node] = -1;
        return;
    }


    ll leftNode = 2*node, rightNode = 2*node+1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

//    show(node);
//    show(bg);
//    show(ed);
//    show(Tree[leftNode]);
//    show(Tree[rightNode]);
//    cout << "\n";

    Tree[node] = max(Tree[leftNode], Tree[rightNode]);
}

void Update(ll node, ll bg, ll ed, ll idx, ll val)
{
    if(bg == ed)
    {
        Tree[node] = val;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node+1;
    ll mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = max(Tree[leftNode], Tree[rightNode]);
}

ll Query(ll node, ll bg, ll ed, ll l, ll r)
{
    if(l > ed || r < bg)
        return -1;
    if(l <= bg && ed <= r)
        return Tree[node];

    ll leftNode = 2*node, rightNode = 2*node+1;
    ll mid = (bg + ed)/2;

    return max(Query(leftNode, bg, mid, l, r), Query(rightNode, mid+1, ed, l, r));
}

void solve(int caseno)
{
    ll n, d, i, j, pos, sortedIdx, ans;

    cin >> n >> d;

    for(i = 1; i <= n; i++)
    {
        cin >> h[i];
        hSortedRev[{h[i], i}] = 0;
    }

    i = 1;
    for(auto u : hSortedRev)
    {
        hSortedRev[u.ff] = i;
        hSorted[i] = u.ff.ff;
        i++;
    }


//    for(auto u : hSortedRev)
//    {
//        show(u.ff.ff);
//        show(u.ff.ss);
//        show(u.ss);
//        cout << "\n";
//    }

//    for(i = 1; i <= n; i++)
//        cout << hSorted[i] << " ";
//    cout << "\n";

    Build(1, 1, n);

//    cout << "Query: ";
//    cout << Query(1, 1, n, 2, 5) << "\n";

//    cout << "Tree: ";
//    for(i = 1; i <= 9; i++)
//        cout << Tree[i] << " ";
//    cout << "\n";

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        sortedIdx = hSortedRev[{h[i], i}];

//        show(i);

        pos = upper_bound(hSorted+1, hSorted+n+1, h[i] - d) - hSorted-1;
        steps[sortedIdx] = Query(1, 1, n, 1, pos) + 1;

//        show(pos);
////        show(steps[sortedIdx]);
//        cout << Query(1, 1, n, 1, pos) << "; ";

        pos = lower_bound(hSorted+1, hSorted+n+1, h[i] + d) - hSorted-1;
        steps[sortedIdx] = max(steps[sortedIdx], Query(1, 1, n, pos+1, n) + 1);

//        show(pos);
////        show(steps[sortedIdx]);
//        cout << Query(1, 1, n, pos+1, n) << "; ";
//        cout << "\n";

        Update(1, 1, n, sortedIdx, steps[sortedIdx]);

        ans = max(ans, steps[sortedIdx]);
    }

    cout << ans+1 << "\n";
    for(i = 1, j = 0; i <= n; i++)
    {
        sortedIdx = hSortedRev[{h[i], i}];

        if(steps[sortedIdx] == j)
        {
            cout << i << " ";
            j++;
        }
    }
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


