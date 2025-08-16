#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, m, k, lat;

    cin >> n >> m >> k;

    m = abs(m);
    n = abs(n);

    if(n > m)
        swap(m, n);

    if(k < m)
    {
        cout << "-1\n";
        return;
    }

    lat = (m-n)%2;

    if(lat)
        cout << k-1 << "\n";
    else if((k-n)%2 == 0)
        cout << k << "\n";
    else
        cout << k-2 << "\n";
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