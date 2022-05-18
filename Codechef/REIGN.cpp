#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];
ll fromLeft[100005], fromRight[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, k, i, ans;
    
    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 1; i <= n; i++)
            cin >> a[i];
            
        fromLeft[0] = fromRight[n+1] = 0;
        for(i = 1; i <= n; i++)
        {
            fromLeft[i] = max(a[i], fromLeft[i-1] + a[i]);
            fromRight[n-i+1] = max(a[n-i+1], fromRight[n-i+2] + a[n-i+1]);
        }

        for(i = 2; i <= n; i++)
        {
            fromLeft[i] = max(fromLeft[i-1], fromLeft[i]);
            fromRight[n-i+1] = max(fromRight[n-i+1], fromRight[n-i+2]);
        }

        // for(i = 1; i <= n; i++)
        //     cout << fromLeft[i] << " " << fromRight[i] << "\n";
        // cout << "\n";

        ans = LLONG_MIN;
        for(i = 1; i + k + 1 <= n; i++)        
            ans = max(ans, fromLeft[i] + fromRight[i+k+1]);
        
        cout << ans << "\n";
    }
}