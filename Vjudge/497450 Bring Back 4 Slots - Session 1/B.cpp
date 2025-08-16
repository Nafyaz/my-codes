#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, a, ans = 0;
    cin >> n;

    while(n--)
    {
        cin >> a;
        ans += a;
    }

    cout << ans << "\n";
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