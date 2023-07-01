#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005];
ll pref[500005];
ll sparse[500005][20];
ll Log[500005];

ll findMax(ll i, ll j)
{
    ll k = Log(j-i+1);

    return max(sparse[i][k], sparse[j-(1LL<<k)+1][k]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, ans, mx, low, high, mid;

    for(i = 2; i < 500005; i++)
    {
        Log[i] = Log[i/2] + 1;
    }

    cin >> T;

    while(T--)
    {
        cin >> n;

        pref[0] = 0;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];

            pref[i] = pref[i-1] + a[i];
            sparse[i][0] = pref[i];
        }
    }

    for(j = 1; j < 20; j++)
    {
        for(i = 1; i + (1LL << j) -1 <= n; i++)
        {
            sparse[i][j] = max(sparse[i][j-1], sparse[i+(1LL << (j-1))][j-1]);
        }
    }

    ans = 0;
    i = 1;
    while(i <= n)
    {
        mx = findMax(i, n) - pref[i-1];

        if(mx < 0)
        {
            ans ++;
            i++;
            continue;
        }

        low = i;
        high = n-1;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(findMax(i, mid) < mx)
            {
                low = mid + 1;
                continue;
            }
            if()
        }
    }
}
