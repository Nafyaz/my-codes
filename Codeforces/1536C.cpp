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
    ll n, i, d, k, g;
    string s;

    map<pll, ll> mp;

    cin >> n >> s;

    d = k = 0;
    for(i = 0; i < s.size(); i++)
    {
        d += (s[i] == 'D');
        k += (s[i] == 'K');

        if(!d || !k)
            cout << max(d, k) << " ";
        else
        {
            g = __gcd(d, k);
            cout << mp[{d/g, k/g}] + 1 << " ";
            mp[{d/g, k/g}] ++;
        }
    }

    cout << "\n";
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