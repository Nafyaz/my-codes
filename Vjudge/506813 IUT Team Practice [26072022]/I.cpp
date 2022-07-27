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

ll coins[MAXN];
ll Tree[4*MAXN], Lazy[4*MAXN];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Lazy[node] = 0;
        Tree[node] = 0;
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = max(Tree[leftNode], Tree[rightNode]);
    Lazy[node] = 0;
}

void updateRange(ll node, ll bg, ll ed, ll l, ll r, ll val)
{
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return;

    if(l <= bg && ed <= r)
    {
        Tree[node] += val;
        if(bg != ed)
        {
            Lazy[leftNode] += val;
            Lazy[rightNode] += val;
        }
        return;
    }

    updateRange(leftNode, bg, mid, l, r, val);
    updateRange(rightNode, mid+1, ed, l, r, val);

    Tree[node] = max(Tree[leftNode], Tree[rightNode]);
}

ll queryRange(ll node, ll bg, ll ed, ll l, ll r)
{    
    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    if(Lazy[node] != 0)
    {
        Tree[node] += Lazy[node];
        if(bg != ed)
        {
            Lazy[leftNode] += Lazy[node];
            Lazy[rightNode] += Lazy[node];
        }
        Lazy[node] = 0;
    }

    if(bg > r || ed < l)
        return LLONG_MIN;

    if(l <= bg && ed <= r)
        return Tree[node];

    ll p1 = queryRange(leftNode, bg, mid, l, r);
    ll p2 = queryRange(rightNode, mid + 1, ed, l, r);
    
    return max(p1, p2);
}

void solve(int caseno)
{
    ll n, q, i, j, type, idx, val, ans;

    cin >> n;

    Build(1, 1, n-1);

    for(i = 0; i < n; i++)
    {
        cin >> coins[i];

        if(i == 0)        
            updateRange(1, 1, n-1, 1, n-1, coins[i]);
        else
        {
            for(j = 1; j*j <= i; j++)
            {
                if(i%j == 0)
                {
                    updateRange(1, 1, n-1, j, j, coins[i]);
                    
                    if(j*j != i)
                        updateRange(1, 1, n-1, i/j, i/j, coins[i]);
                }
            }
        }
    }

    cin >> q;
    cout << "Case " << caseno << ":\n";

    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            ans = LLONG_MIN;

            for(j = 1; j*j <= n-1; j++)
            {
                if(idx%j == 0)
                {
                    ans = max(ans, queryRange(1, 1, n-1, j, j));
                    
                    if(j*j != n-1)
                        ans = max(ans, queryRange(1, 1, n-1, (n-1)/j, (n-1)/j));
                }
            }

            cout << ans << "\n";
        }
        else
        {
            cin >> idx >> val;
            idx--;

            if(idx == 0)
            {
                updateRange(1, 1, n-1, 1, n-1, val - coins[0]);
                coins[0] = val;
            }
            else
            {
                for(j = 1; j*j <= idx; j++)
                {
                    if(idx%j == 0)
                    {
                        updateRange(1, 1, n-1, j, j, val - coins[idx]);
                        
                        if(j*j != idx)
                            updateRange(1, 1, n-1, idx/j, idx/j, val - coins[idx]);
                    }
                }

                coins[idx] = val;
            }
        }
    }
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