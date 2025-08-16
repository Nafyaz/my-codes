#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN], brr[MAXN];

void solve(ll caseno)
{
    ll n, i, ans;

    cin >> n;

    map<ll, ll> mp;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        brr[i] = brr[i-1] ^ arr[i];
        mp[brr[i]]++;
    }

    ans = mp.size();
    for(i = 1; i <= n; i++)
    {
        mp[brr[i]]--;
        if(mp[brr[i]] == 0)
            mp.erase(brr[i]);

        brr[i+n] = brr[i+n-1] ^ arr[i];
        mp[brr[i+n]]++;

        ans = max(ans, (ll)mp.size());
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}