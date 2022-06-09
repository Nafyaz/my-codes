#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

ll a[30004];
ll Tree[120005];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node] = a[bg];
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid + 1, ed);

    Tree[node] = min(Tree[leftNode], Tree[rightNode]);
}

ll leftQuery(ll node, ll bg, ll ed, ll i)
{
    if(Tree[node] >= a[i])
        return bg;
    else if(bg == ed)
        return -1;

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;


    if(i <= mid)
    {
        ll p = leftQuery(leftNode, bg, mid, i);
        return p;
    }
    else
    {
        ll q = leftQuery(rightNode, mid+1, ed, i);
        if(q != mid + 1)
            return q;

        ll p = leftQuery(leftNode, bg, mid, i);
        if(p != -1)
            return p;
        else
            return q;
    }
}

ll rightQuery(ll node, ll bg, ll ed, ll i)
{
    if(Tree[node] >= a[i])
        return ed;
    else if(bg == ed)
        return -1;

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(i >= mid+1)
    {
        ll q = rightQuery(rightNode, mid + 1, ed, i);
        return q;
    }
    else
    {
        ll p = rightQuery(leftNode, bg, mid, i);
        if(p != mid)
            return p;

        ll q = rightQuery(rightNode, mid + 1, ed, i);
        if(q != -1)
            return q;
        else
            return p;
    }
}

void solve(ll caseno)
{
    ll n, i, leftMost, rightMost, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    Build(1, 1, n);

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        leftMost = leftQuery(1, 1, n, i);
        rightMost = rightQuery(1, 1, n, i);

        ans = max(ans, a[i]*(rightMost - leftMost + 1));
    }

    cout << "Case " << caseno << ": " << ans << "\n";
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