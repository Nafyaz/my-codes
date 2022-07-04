#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<ll> v;

ll getRev(ll x)
{
    ll ret = 0;
    while(x)
    {
        ret = ret*10 + x%10;
        x /= 10;
    }

    return ret;
}

void solve(ll caseno)
{
    ll a, b;

    cin >> a >> b;

    cout << lower_bound(v.begin(), v.end(), b+1) - lower_bound(v.begin(), v.end(), a) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0, i, x, sq;

    for(i = 1; i < MAXN; i++)
    {
        x = getRev(i*i);
        sq = sqrt(x);

        if(sq*sq == x && (ll)log10(i*i) == (ll)log10(x))
            v.push_back(i*i);
    }

    while(T--)
    {
        solve(++caseno);
    }
}