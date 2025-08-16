#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    ll n, i, a, ans;
    map<ll, ll> mp;

    cin >> T;

    while(T--)
    {
        cin >> n;

        mp.clear();

        for(i = 0; i < n; i++)
        {
            cin >> a;

            mp[abs(a)] = a;
        }

        ans = 0;
        for(auto u : mp)
            ans += u.second;

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
