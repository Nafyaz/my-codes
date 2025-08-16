#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

ll n;
ll arr[100005];
ll Tree[4*100005];
multiset<pair<ll, ll>> ms;

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node] = bg;
        return;
    }

    int leftNode = 2*node, rightNode = 2*node+1;
    int mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    if(arr[Tree[leftNode]] > arr[Tree[rightNode]])
        Tree[node] = Tree[leftNode];
    else
        Tree[node] = Tree[rightNode];
}

void Update(ll node, ll bg, ll ed, ll idx, ll val)
{
    if(bg == ed)
    {
        arr[bg] = val;
        Tree[node] = bg;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node+1;
    ll mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    if(arr[Tree[leftNode]] > arr[Tree[rightNode]])
        Tree[node] = Tree[leftNode];
    else
        Tree[node] = Tree[rightNode];
}

ll Query(ll node, ll bg, ll ed, ll l, ll r)
{
    if(l > ed || r < bg)
        return -1;
    if(l <= bg && ed <= r)
        return Tree[node];

    ll leftNode = 2*node, rightNode = 2*node+1;
    ll mid = (bg + ed)/2;

    ll ret1 = Query(leftNode, bg, mid, l, r);
    ll ret2 = Query(rightNode, mid+1, ed, l, r);

    if(ret1 == -1 && ret2 == -1)
        return -1;
    if(ret1 == -1 || ret2 == -1)
        return max(ret1, ret2);

    if(arr[ret1] > arr[ret2])
        return ret1;
    else
        return ret2;
}

void clearMS()
{
    while(!ms.empty())
    {
        ll val = (*ms.begin()).ff;
        ll idx = (*ms.begin()).ss;

        ms.erase(ms.begin());

        Update(1, 1, n, idx, val);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q, i, type, idx, val, l, r;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    Build(1, 1, n);

    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> idx >> val;
            Update(1, 1, n, idx, val);

//            cout << "Tree: ";
//            for(i = 1; i <= 9; i++)
//                cout << Tree[i] << " ";
//            cout << "\n";
        }
        else
        {
            cin >> l >> r;

            //1
            idx = Query(1, 1, n, l, r);
            if(arr[idx] == -1)
            {
                cout << "0\n";
                clearMS();
                continue;
            }
            val = arr[idx];
            Update(1, 1, n, idx, -1);
            ms.insert({val, idx});


            //2
            idx = Query(1, 1, n, l, r);
            if(arr[idx] == -1)
            {
                cout << "0\n";
                clearMS();
                continue;
            }
            val = arr[idx];
            Update(1, 1, n, idx, -1);
            ms.insert({val, idx});

            bool flag = 0;
            while(1)
            {
                idx = Query(1, 1, n, l, r);
                if(arr[idx] == -1)
                    break;

                val = arr[idx];
                Update(1, 1, n, idx, -1);
                ms.insert({val, idx});

                auto it = ms.begin();
                auto it1 =++it;
                it--;
                auto it2 = ++it1;
                it1--;

//                cout << "MS: ";
//                for(auto u : ms)
//                    cout << u.ff << " " << u.ss << "; ";
//                cout << "\n";
//                show(it->ff);
//                show(it1->ff);
//                show(it2->ff);

                if(it->ff + it1->ff > it2->ff)
                {
                    cout << it->ff + it1->ff + it2->ff << "\n";
                    flag = 1;
                    break;
                }
            }

            clearMS();
            if(!flag)
                cout << "0\n";
        }
    }
}
/*
5 1
3 12 8 9 7
2 1 3
*/