#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, nonZero, groupSize[200005];

bool check(ll m)
{
    ll remaining = m-nonZero, injection, i;

    for(i = 0; i <= n; i++)
    {
        if(!groupSize[i])
            return 1;

        injection = max(0LL, groupSize[i]-m+i);

        if(injection > remaining)
            return 0;

        remaining -= injection;
    }

    return 1;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll T, i, a, low, high, mid, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        fill(groupSize, groupSize+n+1, 0);

        groupSize[0] = 1;
        for(i = 1; i < n; i++)
        {
            cin >> a;
            groupSize[a]++;
        }

        sort(groupSize, groupSize+n+1, greater<ll>());

        nonZero = 0;
        for(i = 0; i <= n; i++)
            nonZero += (groupSize[i] > 0);

        ans = INT_MAX;
        low = nonZero;
        high = n+1;

        while(low <= high)
        {
            mid = (low + high)/2;

            if(check(mid))
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        cout << ans << "\n";
    }
}
