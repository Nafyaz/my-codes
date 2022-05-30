#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll t[200005];

bool isPossible(ll w)
{
    ll i, prev = 0, today;
    for(i = 1; i <= n; i++)
    {
        today = prev + t[i];


        if((i < n && today > 2*w) || (i == n && today > w))
            return 0;

        if(i == n)
            break;

        prev = max(0LL, 2*(today - w));
    }

    return 1;
}

void solve()
{
    ll i;

    cin >> n;

    for(i = 1; i <= n; i++)    
        cin >> t[i];
    
    ll low, mid, high, ans;

    low = 0;
    high = 200005;

    while(low <= high)
    {
        mid = (low + high) >> 1;

        if(isPossible(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}