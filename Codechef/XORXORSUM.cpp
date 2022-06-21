#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll arr[MAXN];

void solve(ll caseno)
{
    ll n, i, bit, nxtXor, b, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    ans = 0;
    for(i = 1; i < n; i++)
    {
        nxtXor = b = 0;
        for(bit = 1; bit < (1LL << 61); bit *= 2)
        {
            if((arr[i] & bit) != 0 && nxtXor == 0)            
                b += bit;            
            else if((arr[i] & bit) == 0 && nxtXor != 0)
                b += bit;

            nxtXor = (arr[i] & bit) & (b & bit);
        }

        // show(arr[i]);
        // show(b);
        // cout << "\n";

        ans += upper_bound(arr, arr+i, b) - lower_bound(arr, arr+i, b);
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