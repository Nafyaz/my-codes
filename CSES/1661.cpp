#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr;
map<ll, ll> mp;

void solve(ll caseno)
{
    ll n, x, i, sum = 0, ans = 0;

    cin >> n >> x;

    mp[0] = 1;
    for(i = 0; i < n; i++)
    {
        cin >> arr;

        sum += arr;

        ans += mp[sum - x];

        mp[sum] ++;
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