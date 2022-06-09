#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

ll cSum[100005];

ll bigmod(ll a, ll p)
{
    if(!p)
        return 1;
    
    ll ret = bigmod(a, p/2);
    ret = (ret * ret) % mod;

    if(p&1)
        ret = (ret * a) % mod;

    return ret;
}

void solve(ll caseno)
{
    ll n, q, i, l, r, ones, zeros, ans, temp;
    string s;

    cin >> n >> q;

    cin >> s;
    for(i = 1; i <= n; i++)
        cSum[i] = cSum[i-1] + (s[i-1] == '1');

    for(i = 1; i <= q; i++)
    {
        cin >> l >> r;

        ones = cSum[r] - cSum[l-1];
        zeros = r-l+1 - ones;

        if(n > 100)
        {
            if(q == 1622)
            cout << l << " " << r << "\n";
            cout << ones << " " << zeros << "\n";

        }


        // // show(zeros);
        // // show(ones);
        // // cout << "\n";

        // if(ones == 0)
        //     cout << "0\n";
        // else
        // {
        //     temp = (bigmod(2, ones) - 1)%mod;
        //     ans = (temp + (temp*(bigmod(2, zeros) - 1)) % mod) % mod;
        // }

        // cout << ans << "\n";
    }
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