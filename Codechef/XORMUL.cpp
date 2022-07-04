#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, a, b, i, bit, x, y, z;
    vector<ll> v;

    cin >> n >> a >> b;

    x = 0;
    for(i = 0, bit = 1; i < n; i++, bit *= 2)
    {
        if((a&bit) == 0 && (b&bit) == 0)
            x += bit;
        else if((a&bit) == 0 || (b&bit) == 0)
        {
            v.push_back(bit);
        }
    }

    reverse(v.begin(), v.end());

    for(i = 0; i < v.size(); i++)
    {
        if(abs((a^(x+v[i])) - (b^(x+v[i]))) < abs((a^x) - (b^x)))
            x += v[i];
    }

    cout << x << "\n";
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