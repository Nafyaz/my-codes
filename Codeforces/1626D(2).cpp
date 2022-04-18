#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

ll cost(ll x)
{
    ll ret = 1;

    while(ret < x)
        ret *= 2;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, lw, mw, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        ans = cost(n) + cost(0) + cost(0);

        for(i = 0; i < n; i++)
        {
            if(i+1 < n && a[i] == a[i+1])
                continue;

            lw = i+1;
            ans = min(ans, cost(lw) + cost(0) + cost(n-lw));

            for(j = 0; j < 32; j++)
            {
                mw = min(n, lw + (1LL << j)) - mw;
            }
        }
    }
}
