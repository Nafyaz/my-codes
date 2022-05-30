#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

void solve()
{
    ll i, n, m, total = 0, b;

    cin >> n;

    for(i = 0; i < n; i++)    
        cin >> a[i];
    
    cin >> m;
    while(m--)
    {
        cin >> b;
        total += b;
    }

    cout << a[total%n] << "\n";
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