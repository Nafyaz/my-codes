#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[30], b[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, c1, c2, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
            cin >> b[i];

        ans = 0;
        for(i = 1; i < n; i++)
        {
            c1 = abs(a[i-1]-a[i]) + abs(b[i-1]-b[i]);
            c2 = abs(a[i-1]-b[i]) + abs(b[i-1]-a[i]);

            ans += min(c1, c2);
        }

        cout << ans << "\n";
    }
}
