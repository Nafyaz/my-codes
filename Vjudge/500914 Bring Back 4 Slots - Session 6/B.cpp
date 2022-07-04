#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

map<ll, ll> freq;
vector<pll> pref;

void solve(ll caseno)
{
    ll s, n, i, q, x, pos;

    cin >> s >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    for(auto u : freq)    
    {
        if(pref.empty())
            pref.push_back({u.ss, u.ff});
        else
            pref.push_back({pref.back().ff + u.ss, u.ff});
    }

    if(pref.back().ss != s)
        pref.push_back({pref.back().ff, s});

    // for(auto u : pref)
    //     cout << u.ff << " " << u.ss << "\n";

    cin >> q;

    while(q--)
    {
        cin >> x;

        pos = upper_bound(pref.begin(), pref.end(), make_pair(x, (ll)INT_MAX)) - pref.begin();

        // cout << x << " ";
        if(pos == 0)
            cout << "0\n";
        else
            cout << pref[pos-1].ss << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}