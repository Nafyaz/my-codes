#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll a[200005];
pair<ll, ll> tree[4*200005];

void build(ll node, ll s, ll e)
{
    if(s == e)
    {
        tree[node] = {a[s], s};
        return;
    }

    ll mid = (s+e)/2, left = 2*node, right = 2*node + 1;

    build(left, s, mid);
    build(right, mid+1, e);

    if(tree[left].ff <= tree[right].ff)
        tree[node] = tree[left];
    else
        tree[node] = tree[right];
}

void update(ll node, ll s, ll e, ll idx, ll val)
{
    if(s == e)
    {
        a[idx] = val;
        tree[node] = {val, s};
        return;
    }

    ll mid = (s+e)/2, left = 2*node, right = 2*node + 1;

    if(idx <= mid)
        update(left, s, mid, idx, val);
    else
        update(right, mid+1, e, idx, val);

    if(tree[left].ff <= tree[right].ff)
        tree[node] = tree[left];
    else
        tree[node] = tree[right];
}

pair<ll, ll> query(ll node, ll s, ll e, ll l, ll r)
{
    if(l > e || r < s)
        return {INT_MAX, -1};

    if(l <= s && r >= e)
        return tree[node];

    ll mid = (s+e)/2, left = 2*node, right = 2*node + 1;
    pair<ll, ll> p1 = query(left, s, mid, l, r);
    pair<ll, ll> p2 = query(right, mid+1, e, l, r);

    if(p1.ff <= p2.ff)
        return p1;
    else
        return p2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, k, i, x, curr, killSum;
    pair<ll, ll> mn;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        build(1, 1, n);

        x = curr = killSum = 0;
        for(i = 0; i < n; i++)
        {
            mn = query(1, 1, n, 1, min(k+i, n));
            killSum += mn.ff;

            if(curr < mn.ff)
                x += mn.ff-curr;

            curr = x + killSum;

            update(1, 1, n, mn.ss, INT_MAX);
        }

        cout << x << "\n";
    }
}
