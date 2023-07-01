#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll getEmotes(ll k, ll l)
{
    if(l <= k)
        return l*(l+1)/2;
    
    ll ret = k*(k+1)/2;
    l -= k;

    ret += (k-1)*k/2 - (k-l-1)*(k-l)/2;

    return ret;
}

void solve()
{
    ll k, x, lines, low, high, mid;

    cin >> k >> x;

    low = 0;
    high = 2*k - 1;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(getEmotes(k, mid) > x)
            high = mid - 1;
        else
        {
            lines = mid;
            low = mid + 1;
        }
    }

    // cout << getEmotes(3, 4);

    // cout << "lines: " << lines << "\n";
    if(getEmotes(k, lines) < x && getEmotes(k, lines+1) > x)
        cout << lines + 1 << "\n";
    else
        cout << lines << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}