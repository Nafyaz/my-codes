#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n, x, y;

ll calc(ll s)
{
    ll left, right, up, down;
    ll upperRight, upperLeft, lowerRight, lowerLeft;
    ll ret = 1;

    ret += 2*s*(s+1);

    right = max(0LL, y+s-n);
    ret -= right*right;

    left = max(0LL, 1-y+s);
    ret -= left*left;

    up = max(0LL, 1-x+s);
    ret -= up*up;

    down = max(0LL, x+s-n);
    ret -= down*down;

    upperRight = max(0LL, y+up-1-n);
    ret += upperRight*(upperRight + 1) / 2;

    upperLeft = max(0LL, 1-y+up-1);
    ret += upperLeft*(upperLeft + 1) / 2;

    lowerRight = max(0LL, y+down-1-n);
    ret += lowerRight*(lowerRight + 1) / 2;

    lowerLeft = max(0LL, 1-y+down-1);
    ret += lowerLeft*(lowerLeft + 1) / 2;

    // show(left);
    // show(right);
    // show(up);
    // show(down);
    // cout << "\n";
    // show(upperRight);
    // show(upperLeft);
    // show(lowerRight);
    // show(lowerLeft);
    // cout << "\n";

    return ret;
}

void solve(ll caseno)
{
    ll c, low, high, mid, val, ans;
    
    cin >> n >> x >> y >> c;

    // show(calc(4));
    // cout << "\n";
    // for(ll i = 0; i < 18; i++)
    // {
    //     show(i);
    //     show(calc(i));
    //     cout << "\n";
    // }

    low = 0;
    high = 2*n;
    while(low <= high)
    {
        mid = (low + high) / 2;
        val = calc(mid);

        if(val >= c)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}