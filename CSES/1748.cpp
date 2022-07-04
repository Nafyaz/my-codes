#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll mx;
ll arr[MAXN], BIT[MAXN];
vector<pll> v;

void Update(ll i, ll d)
{
    while(i <= mx)
    {
        BIT[i] = (BIT[i] + d) % MOD;
        i += i & (-i);
    }
}

ll Query(ll i)
{
    ll sum = 0;
    while(i > 0)
    {
        sum = (sum + BIT[i]) % MOD;
        i -= i & (-i);
    }
    
    return sum;
}

void solve(ll caseno)
{
    ll n, x, i, val, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;

        v.push_back({x, i});
    }

    sort(v.begin(), v.end());

    val = 1;
    for(i = 0; i < n; i++)
    {
        if(i != 0 && v[i-1].ff == v[i].ff)
            arr[v[i].ss] = val;
        else
        {
            val++;
            arr[v[i].ss] = val;
        }

        mx = val;
    }

    ans = 0;
    for(i = 0; i < n; i++)
    {
        val = Query(arr[i] - 1);
        ans = (ans + val + 1) % MOD;
        Update(arr[i], val+1);
    }

    cout << ans << "\n";
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