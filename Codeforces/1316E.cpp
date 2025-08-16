#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll n, p, k;
ll arr[MAXN];
pair<vector<ll>, ll> s[MAXN];
ll dp[MAXN][1LL << 7];

ll call(ll pos, ll audi, ll mask)
{
    ll bit, ret = 0;

    if(pos >= n)
        return 0;

    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    if(audi < k)
        ret = max(ret, arr[pos] + call(pos+1, audi+1, mask));
    else
        ret = max(ret, call(pos+1, audi, mask));

    for(bit = 0; bit < p; bit++)
    {
        if((mask & (1LL << bit)) == 0)
            ret = max(ret, s[pos].ff[bit] + call(pos+1, audi, mask | (1LL << bit)));
    }

    // if(audi == 2)
    // {
    //     show(pos);
    //     show(mask);
    //     show(ret);
    //     cout << "\n";
    // }

    return dp[pos][mask] = ret;
}

void solve(ll caseno)
{
    ll i, j, temp;

    cin >> n >> p >> k;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    for(i = 0; i < n; i++)
    {
        s[i].ss = i;
        for(j = 0; j < p; j++)
        {
            cin >> temp;
            s[i].ff.push_back(temp);
        }
    }

    sort(s, s+n,
                [](const pair<vector<ll>, ll> a, const pair<vector<ll>, ll> b){
                return arr[a.second] > arr[b.second];
    });
    sort(arr, arr+n, greater<ll>());

    // cout << "arr:\n";
    // for(i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";
    // cout << "s:\n";
    // for(i = 0; i < n; i++)
    // {
    //     cout << s[i].ss << ": ";
    //     for(auto u : s[i].ff)
    //         cout << u << " ";
    //     cout << "\n";
    // }

    memset(dp, -1, sizeof dp);

    cout << call(0, 0, 0) << "\n";
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
