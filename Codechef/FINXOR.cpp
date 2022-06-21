#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005


void solve(ll caseno)
{
    ll n, bit, sum, mxBit = 20, verdict;
    ll ones, v, ans;

    cin >> n;

    cout << "1 " << (1LL << mxBit) << endl;
    cin >> sum;
    sum -= (n << mxBit);

    // show(sum);
    // cout << "\n";

    ans = (sum&1);

    for(bit = 1; bit < mxBit; bit++)
    {
        cout << "1 " << (1LL << bit) << endl;
        cin >> v;
        ones = (((n << bit) + sum - v)/2) >> bit;

        if(ones&1)
            ans += (1LL << bit);

        // show(v);
        // show(ones);
        // show(ans);
        // cout << "\n";
    }

    cout << "2 " << ans << endl;
    cin >> verdict;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}