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
    ll a, b;

    cin >> a >> b;

    while(a && b)
    {
        cout << "10";
        a--;
        b--;
    }

    while(a)
    {        
        cout << "0";
        a--;
    }

    while(b)
    {
        cout << "1";
        b--;
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