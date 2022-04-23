#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll a[100005];
pair<ll, ll> Tree[4*100005];

void build(ll node, ll st, ll ed)
{
    if(st == ed)
    {
        Tree[node] = {st, a[st]};
        return;
    }

    ll leftNode = 2*node+1, rightNode = 2*node+2;
    ll mid = (st + ed)/2;

    build(leftNode, st, mid);
    build(rightNode, mid+1, ed);

    if(Tree[leftNode].ss <= Tree[rightNode].ss)
        Tree[node] = Tree[leftNode];
    else
        Tree[node] = Tree[rightNode];

    return;
}

void update(ll node, ll st, ll ed, ll idx, ll val)
{
    if(st == ed)
    {
        a[idx] = val;
        Tree[node] = {st, val};
        return;
    }

    ll leftNode = 2*node+1, rightNode = 2*node+2;
    ll mid = (st + ed)/2;

    if(st <= idx && idx <= mid)
        update(leftNode, st, mid, idx, val);
    else
        update(rightNode, mid+1, ed, idx, val);

    if(Tree[leftNode].ss <= Tree[rightNode].ss)
        Tree[node] = Tree[leftNode];
    else
        Tree[node] = Tree[rightNode];

    return;
}

pair<ll, ll> query(ll node, ll st, ll ed, ll l, ll r)
{
    if(ed < l || r < st)
        return {-1, INT_MAX};

    if(l <= st && ed <= r)
        return Tree[node];

    ll leftNode = 2*node+1, rightNode = 2*node+2;
    ll mid = (st + ed)/2;

    pair<ll, ll> p = query(leftNode, st, mid, l, r);
    pair<ll, ll> q = query(rightNode, mid+1, ed, l, r);

    if(p.ss <= q.ss)
        return p;
    else
        return q;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, q, l, r, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        build(0, 0, n-1);

        cin >> q;
        while(q--)
        {
            cin >> l >> r;

            l--;
            r--;

            vector<pair<ll, ll>> min31;

            for(i = 0; i < min(31LL, r-l+1); i++)
            {
                min31.push_back(query(0, 0, n-1, l, r));
                update(0, 0, n-1, min31.back().ff, INT_MAX);
            }

//            cout << "Tree:\n";
//            for(i = 0; i < 4*n; i++)
//                cout << "i: " << i << "; ff: " << Tree[i].ff << "; ss: " << Tree[i].ss << "\n";
//            cout << "\n";
//
//            cout << "min31:\n";
//            for(i = 0; i < min31.size(); i++)
//                cout << min31[i].ff << " " << min31[i].ss << "\n";
//            cout << "\n";

            ans = INT_MAX;
            for(i = 0; i < min31.size(); i++)
            {
                for(j = i+1; j < min31.size(); j++)
                    ans = min(ans, min31[i].ss | min31[j].ss);
            }

            cout << ans << "\n";

            for(i = 0; i < min31.size(); i++)
                update(0, 0, n-1, min31[i].ff, min31[i].ss);
        }
    }
}
