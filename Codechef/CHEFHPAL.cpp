#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

void solve()
{
    ll n, a, i, j;
    string s;

    cin >> n >> a;

    cout << (n + a - 1)/a << " ";
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < n/a; j++)
            cout << char('a' + i);
        if(i < n%a)
            cout << char('a' + i);
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1;

    cin >> T;

    while(T--)
    {
        solve();
    }
}