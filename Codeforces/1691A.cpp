#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

void solve(ll caseno)
{
    ll n, i, a, odd;

    cin >> n;

    odd = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        odd += (a&1);
    }    

    cout << min(odd, n-odd) << "\n";
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