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

ll arr[MAXN];
ll Tree[4*MAXN], Lazy[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Lazy[node] = 0;
        Tree[node] = arr[bg];
        return;
    }

    ll leftNode = 2*node + 1, rightNode = 2*node + 2;
    ll mid = (bg + ed) / 2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid + 1, ed);

    Tree[node] = min(Tree[leftNode], Tree[rightNode]);
    Lazy[node] = 0;

    return;
}

void Update(ll node, ll bg, ll ed, ll l, ll r, ll v)
{
    ll leftNode = 2*node + 1, rightNode = 2*node + 2;
    ll mid = (bg + ed) / 2;

    if(Lazy[node] != 0)
    {
        Tree[node] += Lazy[node];

        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        else
            arr[bg] += Lazy[node];

        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return;

    if(l <= bg && ed <= r)
    {
        Tree[node] += v;

        if(bg != ed)
        {
            Lazy[leftNode] += v;
            Lazy[rightNode] += v;
        }
        else
            arr[bg] += v;

        return;
    }

    Update(leftNode, bg, mid, l, r, v);
    Update(rightNode, mid+1, ed, l, r, v);

    Tree[node] = min(Tree[leftNode], Tree[rightNode]);
}

ll Query(ll node, ll bg, ll ed, ll l, ll r)
{
    ll leftNode = 2*node + 1, rightNode = 2*node + 2;
    ll mid = (bg + ed) / 2;

    if(Lazy[node] != 0)
    {
        Tree[node] += Lazy[node];

        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        else
            arr[bg] += Lazy[node];

        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return LLONG_MAX;

    if(l <= bg && ed <= r)
        return Tree[node];

    return min(Query(leftNode, bg, mid, l, r), Query(rightNode, mid+1, ed, l, r));
}

void solve(ll caseno)
{
    ll n, m, i, x, bg, ed, v;
    string s;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    Build(0, 0, n-1);

    cin >> m;
    getline(cin, s);

    while(m--)
    {
        getline(cin, s);

        stringstream ss(s);

        vector<ll> temp;
        while(ss >> x)
            temp.push_back(x);


        if(temp.size() == 3)
        {
            bg = temp[0];
            ed = temp[1];
            v = temp[2];

            if(bg > ed)
            {
                Update(0, 0, n-1, bg, n-1, v);
                Update(0, 0, n-1, 0, ed, v);
            }
            else
                Update(0, 0, n-1, bg, ed, v);
        }
        else
        {
            bg = temp[0];
            ed = temp[1];

            if(bg > ed)            
                cout << min(Query(0, 0, n-1, bg, n-1), Query(0, 0, n-1, 0, ed)) << "\n";
            else
                cout << Query(0, 0, n-1, bg, ed) << "\n";
        }
    }
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