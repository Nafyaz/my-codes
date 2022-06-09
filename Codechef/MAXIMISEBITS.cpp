#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

void solve(ll caseno)
{
    ll n, k, bit, ans;

    cin >> n >> k;

    if(k <= n)
    {
        cout << k << "\n";
        return;
    }

    ans = 0;
    for(bit = 1; ; bit *= 2)
    {
        if(bit*n <= k)
        {
            k -= bit*n;
            ans += n;
        }
        else
            break;
    }

    ans += k/bit;
    k %= bit;

    ans -= __builtin_popcountll(bit-1);
    ans += __builtin_popcountll(bit-1 + k);

    cout << ans << "\n";
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