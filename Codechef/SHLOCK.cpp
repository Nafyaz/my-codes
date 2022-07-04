#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll i, ans;
    string s;
    char c, d;

    map<char, vector<ll>> mp;

    cin >> s;

    for(i = 0; i < s.size(); i++)    
        mp[s[i]].push_back(i);
    
    ans = -1;
    for(c = 'a'; c <= 'z'; c++)
    {
        d = 25 - (c - 'a') + 'a';

        if(mp.find(c) != mp.end() && mp.find(d) != mp.end())
        {
            ans = max(ans, abs(mp[c][0] - mp[d].back()));
            ans = max(ans, abs(mp[d][0] - mp[c].back()));
        }
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