#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(ll n)
{
    ll k, ret = 0;
    for(k = 2; k*k*k <= n; k++)
        ret += n / (k*k*k);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m, i, n, k, low, high, mid, ans, val;
    map<ll, ll> mp;

    cin >> m;

    ans = -1;
    low = 1;
    high = 1e18;

    while(low <= high) 
    {
        mid = (low + high) / 2;

        val = calc(mid);

        if(val > m)
            high = mid - 1;
        else if(val < m)
            low = mid + 1;
        else
        {
            high = mid - 1;
            ans = mid;
        }
    }

    cout << ans;
}
