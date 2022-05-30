#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

ll a[50004];
ll mx[200005], mxPref[200005], mxSuff[200005], sum[200005];

void Build(ll node, ll bg, ll ed)
{
    // show(node);
    // show(bg);
    // show(ed);
    // cout << "\n";

    if(bg == ed)
    {
        mx[node] = a[bg];
        mxPref[node] = a[bg];
        mxSuff[node] = a[bg];
        sum[node] = a[bg];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed) / 2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    mx[node] = max({mx[leftNode], mx[rightNode], mxSuff[leftNode] + mxPref[rightNode]});
    mxPref[node] = max(mxPref[leftNode], sum[leftNode] + mxPref[rightNode]);
    mxSuff[node] = max(mxSuff[rightNode], sum[rightNode] + mxSuff[leftNode]);
    sum[node] = sum[leftNode] + sum[rightNode];
}

void Update(ll node, ll bg, ll ed, ll pos, ll val)
{
    if(bg == ed)
    {
        a[pos] = val;
        mx[node] = a[pos];
        mxPref[node] = a[pos];
        mxSuff[node] = a[pos];
        sum[node] = a[pos];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed) / 2;

    if(pos <= mid)
        Update(leftNode, bg, mid, pos, val);
    else
        Update(rightNode, mid+1, ed, pos, val);

    mx[node] = max({mx[leftNode], mx[rightNode], mxSuff[leftNode] + mxPref[rightNode]});
    mxPref[node] = max(mxPref[leftNode], sum[leftNode] + mxPref[rightNode]);
    mxSuff[node] = max(mxSuff[rightNode], sum[rightNode] + mxSuff[leftNode]);
    sum[node] = sum[leftNode] + sum[rightNode];
}

pair<pll, pll> Query(ll node, ll bg, ll ed, ll l, ll r)
{
    if(l <= bg && ed <= r)
        return {{mx[node], mxPref[node]}, {mxSuff[node], sum[node]}};
    if(bg > r || ed < l)
        return {{LLONG_MIN, LLONG_MAX}, {LLONG_MIN, 0}};    
    
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed) / 2;

    pair<pll, pll> leftResult = Query(leftNode, bg, mid, l, r);
    pair<pll, pll> rightResult = Query(rightNode, mid+1, ed, l, r);

    if(l > mid)
        return rightResult;
    else if(r <= mid)
        return leftResult;

    pair<pll, pll> ret;

    ret.ff.ff = max({leftResult.ff.ff, rightResult.ff.ff, leftResult.ss.ff + rightResult.ff.ss});
    ret.ff.ss = max(leftResult.ff.ss, leftResult.ss.ss + rightResult.ff.ss);
    ret.ss.ff = max(rightResult.ss.ff, rightResult.ss.ss + leftResult.ss.ff);
    ret.ss.ss = leftResult.ss.ss + rightResult.ss.ss;

    return ret;
}

void solve()
{
    ll i, n, m, x, y;
    bool type;

    cin >> n;

    for(i = 1; i <= n; i++)    
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << "\n";
    
    Build(1, 1, n);

    // cout << Query(1, 1, n, 1, 3).ff.ff << " " << Query(1, 1, n, 1, 1).ff.ss << " " << Query(1, 1, n, 1, 1).ss.ff << " " << Query(1, 1, n, 1, 1).ss.ss << "\n";

    cin >> m;

    while(m--)
    {
        cin >> type >> x >> y;

        // show(type);
        // show(x);
        // show(y);
        // cout << "\n";

        if(type == 0)        
            Update(1, 1, n, x, y);
        else
        {
            // show(m);
            // cout << "\n";
            cout << Query(1, 1, n, x, y).ff.ff << "\n";
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1;

    // cin >> T;

    while(T--)
    {
        solve();
    }
}