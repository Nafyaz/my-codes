#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m, i, a, ans, mx, mx2;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        mx = mx2 = 0;
        for(i = 0; i < n; i++)        
        {
            cin >> a;
            
            if(mx < a)
            {
                mx2 = (mx == 0? a : mx);
                mx = a;                
            }
            else if(mx2 < a && a < mx)
                mx2 = a;
        }
        
        ans = 2*mx;
        ans = max(ans, mx2 + mx + ((mx2 - mx)%m + m)%m);
        
        cout << ans << "\n";
    }
}