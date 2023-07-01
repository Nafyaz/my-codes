#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, k, x;
ll a[2003], b[2003];
bool c[2003], d[2003];

map<pair<ll, ll>, ll> mp;

ll call(ll pos, ll curr)
{
    if(mp.find({pos, curr}) != mp.end())
        return mp[{pos, curr}];

    if(pos == n)
        return mp[{pos, curr}] = curr;

    if(curr < x-k)
        return mp[{pos, curr}] = call(pos+1, curr + (c[pos]? a[pos] : -b[pos]));
    if(curr > x+k)
        return mp[{pos, curr}] = call(pos+1, curr + (d[pos]? a[pos] : -b[pos]));

    ll ret;

    ret = call(pos+1, curr + (c[pos]? a[pos] : -b[pos]));
    ret = max(ret, call(pos+1, curr + (d[pos]? a[pos] : -b[pos])));

    return mp[{pos, curr}] = ret;
}

void solve()
{
    cin >> n >> k >> x;

    ll i;

    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    mp.clear();
    cout << call(0, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}