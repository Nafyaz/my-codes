#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

ll n, total;
ll h[MAXN];

bool isSuff(ll H, ll one, ll two)
{
    ll i, rem, mn, temp;
    for(i = 0; i < n; i++)
    {
        temp = h[i];
        
        mn = min(H - temp, 2*two)/2*2;
        temp += mn;
        two -= mn/2;

        mn = min(H - temp, one);
        temp += mn;
        one -= mn;

        if(temp != H)
            return 0;
    }

    return 1;
}

ll calc(ll H)
{
    ll low, high, mid, one, two, ret;

    low = 0;
    high = 2*(H*n - total);
    while(low <= high)
    {
        mid = (low + high) / 2;

        one = (mid + 1)/2;
        two = mid / 2;

        // show(mid);
        // show(H);
        // show(one);
        // show(two);
        // cout << "\n";

        if(one + 2*two < (H*n - total) || isSuff(H, one, two) == 0)        
            low = mid + 1;
        else
        {
            high = mid - 1;
            ret = mid;
        }
    }

    return ret;
}

void solve(ll caseno)
{
    ll i, mx;

    cin >> n;

    mx = total = 0;
    for(i = 0; i < n; i++)
    {
        cin >> h[i];
        total += h[i];
        mx = max(mx, h[i]);
    }

    // cout << isSuff(3, 4, 4);
    // calc(3);
    // show(mx);
    // show(calc(mx));
    // show(calc(mx+1));
    // cout << "\n";
    cout << min(calc(mx), calc(mx+1)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}