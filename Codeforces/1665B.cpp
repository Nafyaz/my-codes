#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, mx, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        map<ll, ll> freq;
        mx = 0;

        for(i = 0; i < n; i++)
        {
            cin >> a;
            freq[a]++;

            mx = max(mx, freq[a]);
        }

        ans = 0;
        while(mx < n)
        {
            ans += 1 + min(mx, n-mx);
            mx += min(mx, n-mx);
        }

        cout << ans << "\n";
    }
}
