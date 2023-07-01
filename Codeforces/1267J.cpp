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
    ll n, i, c, s, m, q, y, ans;

    cin >> n;

    map<ll, ll> mp;
    for(i = 0; i < n; i++)
    {
        cin >> c;
        mp[c]++;
    }

    vector<ll> v;
    for(auto u : mp)
        v.push_back(u.ss);
    
    sort(v.begin(), v.end());

    ans = INT_MAX;
    for(s = 1; s <= v[0]+1; s++)
    {
        q = (v[0] + s - 1) / s;
        y = q*s - v[0];

        if(y > q)
            m = -1;
        else
            m = q;

        for(i = 1; i < v.size() && m != -1; i++)
        {
            q = (v[i] + s - 1) / s;
            y = q*s - v[i];

            if(y > q)
                m = -1;
            else
                m += q;
        }

        if(m != -1)
            ans = min(ans, m);
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