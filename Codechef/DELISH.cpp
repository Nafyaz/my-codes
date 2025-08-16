#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, d[10004], pref[10004];
ll maxFrom1[10004], maxFromN[10004];
ll minFrom1[10004], minFromN[10004];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        maxFrom1[0] = maxFromN[n+1] = 0;
        minFrom1[0] = minFromN[n+1] = 0;

        for(i = 1; i <= n; i++)
        {
            cin >> d[i];
            pref[i] = pref[i-1] + d[i];

            maxFrom1[i] = max(maxFrom1[i-1] + d[i], d[i]);
            minFrom1[i] = min(minFrom1[i-1] + d[i], d[i]);

            // cout << maxFrom1[i] << " " << minFrom1[i] << "\n";
        }

        for(i = n; i >= 1; i--)
        {
            maxFromN[i] = max(maxFromN[i+1] + d[i], d[i]);
            minFromN[i] = min(minFromN[i+1] + d[i], d[i]);
        }

        for(i = 2; i <= n; i++)
        {
            maxFrom1[i] = max(maxFrom1[i-1], maxFrom1[i]);
            minFrom1[i] = min(minFrom1[i-1], minFrom1[i]);

            // cout << maxFrom1[i] << " " << minFrom1[i] << "\n";

            maxFromN[n-i+1] = max(maxFromN[n-i+2], maxFromN[n-i+1]);
            minFromN[n-i+1] = min(minFromN[n-i+2], minFromN[n-i+1]);
        }

        ans = LLONG_MIN;
        for(i = 1; i < n; i++)
        {
            ans = max(ans, abs(maxFrom1[i] - minFromN[i+1]));
            ans = max(ans, abs(minFrom1[i] - maxFromN[i+1]));
        }

        cout << ans << "\n";
    }
}