#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005
 
vector<ll>Tree[4*maxN];
ll arr[maxN];

vector<ll> merge(vector<ll> v1, vector<ll> v2)
{
    ll i = 0, j = 0;
    vector<ll> ret;

    while(i < v1.size() || j < v2.size())
    {
        if(i == v1.size())
        {
            ret.push_back(v2[j]);
            j++;
        }
        else if(j == v2.size())
        {
            ret.push_back(v1[i]);
            i++;
        }
        else
        {
            if(v1[i] < v2[j])
            {
                ret.push_back(v1[i]);
                i++;
            }
            else
            {
                ret.push_back(v2[j]);
                j++;
            }
        }
    }

    return ret;
}

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node].push_back(arr[bg]);
        return;
    }

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg+ed)/2;

    Build(leftNode, bg, mid); 
    Build(rightNode, mid+1, ed);

    Tree[node] = merge(Tree[leftNode], Tree[rightNode]);
}
 
ll query(ll node, ll bg, ll ed, ll l, ll r, ll k)
{
    if(ed < l || bg > r)    
        return 0;
    
    if(l <= bg && ed <= r)    
        return upper_bound(Tree[node].begin(), Tree[node].end(), k) - Tree[node].begin();    

    ll leftNode = 2*node, rightNode = 2*node + 1;
    ll mid = (bg + ed)/2;

    return query(leftNode, bg, mid, l, r, k) + query(rightNode, mid+1, ed, l, r, k);
}

void solve(ll caseno)
{
    ll n, m, i, j, k, low, high, mid, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    Build(1, 1, n);
    
    while(m--)
    {
        cin >> i >> j >> k;

        low = INT_MIN;
        high = INT_MAX;
        while(low <= high)
        {
            mid = (low + high)/2;

            if(query(1, 1, n, i, j, mid) >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}