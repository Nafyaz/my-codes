#include<bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << ": " << x << "\n";
#define ll long long

void solve()
{
    ll x, y;

    cin >> x >> y;

    if((x+y) % 2)
        cout << "-1 -1\n";
    else if(x >= y)
        cout << (x-y)/2 << " " << y << "\n";
    else
        cout << x << " " << (y-x)/2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}