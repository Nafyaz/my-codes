#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)        
            cin >> a[i];
        
        sort(a, a+n);

        ans = 0;
        for(i = 0; i < n; i++)
            ans = max(ans, a[i] + a[i]);

        for(i = 1; i < n; i++)
        {
            ans = max(ans, a[i] + a[i-1] + (a[i] - a[i-1])%m);
            ans = max(ans, a[i-1] + a[i] + ((a[i-1] - a[i])%m + m) % m);
        }

        cout << ans << "\n";
    }
}