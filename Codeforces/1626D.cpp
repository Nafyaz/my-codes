//follow Porag_2742
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

map<ll, ll> freq;
ll pref[200005];

ll cost(ll x)
{
    ll ret = 1;

    while(ret < x)
        ret *= 2;

    return ret - x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, x, y, ans, cnt;

    cin >> T;

    while(T--)
    {
        cin >> n;

        freq.clear();
        for(i = 0; i < n; i++)
        {
            cin >> a;
            freq[a]++;
        }

        i = 1;
        for(auto u : freq)
        {
            pref[i] = pref[i-1] + u.ss;
            i++;
        }

        cnt = freq.size() + 1;
        ans = INT_MAX;

        for(x = 0; x < 32; x++)
        {
            for(y = 0; y < 32; y++)
            {
                ll lw = upper_bound(pref, pref+cnt, (1LL<<x)) - pref;
                ll mw = upper_bound(pref, pref+cnt, (pref[lw-1] + (1LL<<y))) - pref;

                ans = min(ans, cost(pref[lw-1]) + cost(pref[mw-1]-pref[lw-1]) + cost(n - pref[mw-1]));
            }
        }

        cout << ans << "\n";
    }
}
