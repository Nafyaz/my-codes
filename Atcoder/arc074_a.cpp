#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll ans;

void calc(ll h, ll w)
{
    ll i, a[3];
    for(i = 0; i <= h; i++)
    {
        // show(i);
        // cout << "\n";

        a[0] = w*i;
        a[1] = w*((h-i)/2);
        a[2] = w*((h-i+1)/2);

        // show(a[0]);
        // show(a[1]);
        // show(a[2]);
        // cout << "\n";

        sort(a, a+3);
        ans = min(ans, a[2] - a[0]);


        a[0] = w*i;
        a[1] = (h-i)*(w/2);
        a[2] = (h-i)*((w+1)/2);

        // show(a[0]);
        // show(a[1]);
        // show(a[2]);
        // cout << "\n\n";

        sort(a, a+3);
        ans = min(ans, a[2] - a[0]);
    }
}

void solve(ll caseno)
{
    ll h, w, i;

    cin >> h >> w;

    if(h%3 == 0 || w%3 == 0)
    {
        cout << "0\n";
        return;
    }

    ans = h*w;
    calc(h, w);
    calc(w, h);
    
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