#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n;
ll m[200005], k[200005];

double findExpected(ll totalMessages, bool willPrint)
{
    ll i;
    double ret;
    map<ll, double> mp;
    vector<pair<double, ll>> v;

    for(i = 0; i < n; i++)    
        mp[m[i]] += min(1.0, (double)k[i]/totalMessages); 
    
    for(auto u : mp)
        v.push_back({u.ss, u.ff});
    sort(v.begin(), v.end(), greater<pair<double, ll>>());

    ret = 0;
    for(i = 0; i < min((ll)v.size(), totalMessages); i++)
    {
        ret += v[i].ff;
        if(willPrint)
            cout << v[i].ss << " ";
    }

    return ret;
}

void solve()
{
    ll i, ans;
    double mx, x;
    
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> m[i] >> k[i];

    mx = ans = 0;
    for(i = 1; i <= 20; i++)
    {
        x = findExpected(i, 0);
        if(mx < x)
        {
            mx = x;
            ans = i;
        }
    }

    cout << ans << "\n";
    findExpected(ans, 1);
    cout << "\n";
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