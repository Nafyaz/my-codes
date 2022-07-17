#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, i, a, ans = 0;
    bool nonZero;

    cin >> n;

    nonZero = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a;

        if(i < n)
        {
            if(a)
                nonZero = 1;

            ans += a;
            if(nonZero && !a)
                ans++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, caseno = 0;

    cin >> t;

    while(t--)
    {
        solve();
    }
}
