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
    map<ll, ll> mp;

    mp[1] = 2;
    mp[2] = 3;
    mp[3] = 4;

    for(auto &[u, v] : mp)
    {
        v += 1;
    }

    for(auto [u, v] : mp)
        cout << u << " " << v << "\n";
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