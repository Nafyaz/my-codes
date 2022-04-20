#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, i, prev, a, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        prev = 2;
        ans = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;

            ans += (a - prev + 4) / 5;
            prev = a;
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
