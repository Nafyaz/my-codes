#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n;
ll a[MAXN];

ll getLIS()
{
    ll i, pos;
    vector<ll> dp;
    for (i = 0; i < n; i++)
    {
        pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (pos == dp.size()) 
            dp.push_back(a[i]);
        else         
            dp[pos] = a[i];
    }
    return dp.size();
}

void solve(ll caseno)
{
    ll i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << getLIS() << "\n";
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