#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> p[2003];
map<pair<pair<ll, ll>, ll>, ll> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, m, d, g, x, y, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i].ff >> p[i].ss;

    sort(p, p+n);

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            x = p[j].ff - p[i].ff;
            y = p[j].ss - p[i].ss;

            g = abs(__gcd(x, y));

            d = x*x + y*y;

            mp[{{y/g, x/g}, d}] ++;
        }
    }

    ans = 0;
    for(auto u : mp)
        ans += u.ss*(u.ss-1)/2;

    cout << ans / 2;
}
