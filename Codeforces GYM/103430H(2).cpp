#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
 
ll n;
ll m[200005], k[200005];
map<ll, ll> freq;
vector<pair<ll, ll>> v;
set<ll> sentMessages;
 
double findExpected()
{
    ll i;
    double ret = 0;
 
    for(i = 0; i < n; i++)
    {
        if(sentMessages.find(m[i]) == sentMessages.end())
            continue;
        
        ret += min(1.0, (double)k[i]/sentMessages.size());
    }
 
    return ret;
}
 
void solve()
{
    ll i, ans;
    double mx, x;
    
    cin >> n;
 
    freq.clear();
    for(i = 0; i < n; i++)
    {
        cin >> m[i] >> k[i];
        freq[m[i]] += k[i];
    }
 
    for(auto u : freq)
        v.push_back({u.ss, u.ff});
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
 
    mx = ans = 0;
    for(i = 1; i <= 20; i++)
    {
        sentMessages.insert(v[i-1].ss);
 
        x = findExpected();
        if(mx < x)
        {
            mx = x;
            ans = i;
        }
    }
 
    cout << ans << "\n";
    for(i = 0; i < ans; i++)
        cout << v[i].ss << " ";
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