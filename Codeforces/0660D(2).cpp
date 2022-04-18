#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> p[2003];
map<pair<ll, ll>, ll> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, x, y, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i].ff >> p[i].ss;

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            x = p[i].ff + p[j].ff;
            y = p[i].ss + p[j].ss;

            mp[{x, y}]++;
        }
    }

    ans = 0;
    for(auto u : mp)
        ans += u.ss*(u.ss-1)/2;

    cout << ans;
}
