#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll a[200005];
pair<ll, ll> b[200005];

void solve()
{
    ll n, k, i, ans = 0;
    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i].ff = (a[i] - (n-i-1));
        b[i].ss = i;
    }

    sort(b, b+n, greater<pair<ll, ll>>());

    // for(i = 0; i < n; i++)
    //     cout << b[i].ff << " " << b[i].ss << endl;
    // cout << "\n";

    for(i = 0; i < n; i++)
    {
        if(i < k)
            ans += (n-b[i].ss-1) - (k-i-1);
        else
            ans += a[b[i].ss];
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;

    while (T--)
    {
        solve();
    }
}