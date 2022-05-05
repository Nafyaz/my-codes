#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, x, i, mx, h, single;

    cin >> T;

    while(T--)
    {
        cin >> n >> x;

        single = 0;
        mx = 0;
        for(i = 0; i < n; i++)
        {
            cin >> h;
            mx = max(mx, h);
            single += (h + x - 1)/x;
        }

        cout << min(single, mx) << "\n";
    }
}