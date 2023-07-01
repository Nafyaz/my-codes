#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

ll a[100005];

void solve(ll caseno)
{
    ll n, i, x, y, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    ans = x = y = 0;
    for(i = n-1; i > 0; i--)
    {
        if(a[i] == a[i-1] || a[i]-1 == a[i-1])
        {
            if(!x)
            {
                x = a[i-1];
                i--;
            }
            else
            {
                y = a[i-1];
                i--;
                
                ans += x*y;
                x = y = 0;
            }
        }
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