#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005

ll m, n;
pll leftQuery[maxN], rightQuery[maxN];
pll x[maxN];
ll ans[maxN];

ll minLeft[4*maxN], maxRight[4*maxN];

void buildMin(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        minLeft[node] = leftQuery[bg].ff;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    buildMin(leftNode, bg, mid);
    buildMin(rightNode, mid+1, ed);

    minLeft[node] = min(minLeft[leftNode], minLeft[rightNode]);
}

ll queryMin(ll node, ll bg, ll ed, ll l, ll r)
{
    if(l <= bg && ed <= r)
        return minLeft[node];
    if(bg > r || ed < l)
        return INT_MAX;

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    return min(queryMin(leftNode, bg, mid, l, r), queryMin(rightNode, mid+1, ed, l, r));
}

void buildMax(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        maxRight[node] = rightQuery[bg].ss;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    buildMax(leftNode, bg, mid);
    buildMax(rightNode, mid+1, ed);

    maxRight[node] = max(maxRight[leftNode], maxRight[rightNode]);
}

ll queryMax(ll node, ll bg, ll ed, ll l, ll r)
{
    if(l <= bg && ed <= r)
        return maxRight[node];
    if(bg > r || ed < l)
        return INT_MIN;

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    return max(queryMax(leftNode, bg, mid, l, r), queryMax(rightNode, mid+1, ed, l, r));
}

bool cmp(pll p, pll q)
{
    if(p.ss != q.ss)
        return p.ss < q.ss;
    return p.ff < q.ff;
}

void solve(ll caseno)
{
    ll i, l, r, curr;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> l >> r;
        leftQuery[i].ff = l;
        leftQuery[i].ss = (l+r)/2;
        rightQuery[i].ff = (l+r+1)/2;
        rightQuery[i].ss = r;
    }

    for(i = 1; i <= m; i++)
    {
        cin >> x[i].ff;
        x[i].ss = i;
        ans[i] = 0;
    }

    sort(leftQuery+1, leftQuery+n+1, cmp);
    sort(rightQuery+1, rightQuery+n+1);
    sort(x+1, x+m+1);

    // for(i = 1; i <= n; i++)
    // {
    //     show(leftQuery[i].ff);
    //     show(leftQuery[i].ss);
    //     cout << "\n";
    // }
    // for(i = 1; i <= n; i++)
    // {
    //     show(rightQuery[i].ff);
    //     show(rightQuery[i].ss);
    //     cout << "\n";
    // }

    buildMin(1, 1, n);
    buildMax(1, 1, n);

    curr = 1;
    for(i = 1; i <= m; i++)
    {
        while(curr <= n && leftQuery[curr].ss < x[i].ff)
            curr++;

        // if(x[i].ss == 2)
        // {
        //     show(i);
        //     show(curr);
        //     cout << "\n";
        // }
        
        if(curr <= n)
            ans[x[i].ss] = max(ans[x[i].ss], x[i].ff - queryMin(1, 1, n, curr, n));
    }

    // show(ans[2]);
    // cout << "\n";

    curr = n;
    for(i = m; i >= 1; i--)
    {
        while(curr >= 1 && rightQuery[curr].ff > x[i].ff)
            curr--;

        // if(x[i].ss == 2)
        // {
        //     show(i);
        //     show(curr);
        //     cout << "\n";
        // }
        
        if(curr >= 1)
            ans[x[i].ss] = max(ans[x[i].ss], queryMax(1, 1, n, 1, curr) - x[i].ff);
    }

    cout << "Case " << caseno << ":\n";
    for(i = 1; i <= m; i++)
        cout << ans[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}