#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

ll a[100005];
ll cSum[31][100005];

void solve(ll caseno)
{
    ll n, q, i, bit, l, r, x;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        for(bit = 0; bit < 31; bit++)        
            cSum[bit][i] = cSum[bit][i-1] + ((a[i] & (1LL << bit)) != 0);        
    }

    while(q--)
    {
        cin >> l >> r;

        x = 0;
        for(bit = 0; bit < 31; bit++)
        {
            if(2*(cSum[bit][r] - cSum[bit][l-1]) < r-l+1)
                x += (1LL << bit);
        }

        cout << x << "\n";
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