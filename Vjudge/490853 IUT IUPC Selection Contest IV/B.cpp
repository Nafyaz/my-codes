#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, k, x, y, i, a, maxA;

    cin >> T;

    while(T--)
    {
        cin >> n >> k >> x >> y;

        maxA = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            maxA = max(a, maxA);
        }

        if(maxA <= x*k)
            cout << (maxA + x - 1)/x << "\n";
        else
            cout << k + (maxA - x*k + y-1)/y << "\n";
    }
}
