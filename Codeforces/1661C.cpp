#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, mx, days, remaining, ans;
    ll h[300005], temp[300005];

    cin >> T;

    while(T--)
    {
        cin >> n;

        mx = 0;
        for(i = 0; i < n; i++)
        {
            cin >> h[i];
            mx = max(mx, h[i]);
        }

        days = 0;
        remaining = 0;
        for(i = 0; < n; i++)
        {
            if((mx - temp[i]) & 1)
            {
                if(days == 0)
                    days = 1;
                else
                    days += 2;
            }

            remaining += (temp[i] - mx)/2*2;
        }

        remaining -= min(remaining, days-1);

        ans = days +
    }
}
