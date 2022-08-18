#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 10020

ll n;
ll arr[MAXN], power[55];
map<pll, ll> dp;

ll call(ll pos, ll prev)
{
    if(pos == n+1)
        return 0;

    if(dp.find({pos, prev}) != dp.end())
        return dp[{pos, prev}];


    ll i, bg = max(1LL, arr[pos] - 7), ed = arr[pos] + 7;
    ll ret = LLONG_MAX, val;
 
    // show(pos);
    // show(prev);
    // show(bg);
    // show(ed);

    for(i = bg; i <= ed; i++)
    {
        if(__gcd(prev, i) == 1)
        {
            val = call(pos+1, i) + power[abs(i - arr[pos])];
            ret = min(ret, val);
        }
    }

    return dp[{pos, prev}] = ret;
}

void solve(int caseno)
{
    ll i;

    cin >> n;

    arr[0] = 1;
    for(i = 1; i <= n; i++)
        cin >> arr[i];

    dp.clear();
    cout << call(1, 1)%MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    power[0] = 1;
    for(ll i = 1; i < 55; i++)
        power[i] = power[i-1] * 2;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
