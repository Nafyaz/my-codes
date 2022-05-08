#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> points[100005];
pair<ll, ll> pref[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, ans;

    cin >> n;

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> points[i].ff >> points[i].ss;
        pref[i].ff = pref[i-1].ff + points[i].ff;
        pref[i].ss = pref[i-1].ss + points[i].ss;

        ans += (n-1)*(points[i].ff*points[i].ff + points[i].ss*points[i].ss);
    }

    for(i = 1; i <= n; i++)    
        ans -= 2*points[i].ff*(pref[n].ff - pref[i].ff) + 2*points[i].ss*(pref[n].ss - pref[i].ss);
    
    cout << ans;
}