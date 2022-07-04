#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005


void solve(ll caseno)
{
    ll n, i, temp, total, req;
    map<ll, ll> MEX;

    cin >> n;

    req = 0;
    for(i = 0; i < n; i++)
    {
        cin >> temp;
        MEX[temp]++;

        req += temp;
    }

    total = n;
    for(i = 0; i < n; i++)
    {
        cout << total - MEX[i] << " " << (total-MEX[i]) + (n - MEX[i])*n - (req - MEX[i]*i) << "\n";

        total -= MEX[i];
    }
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