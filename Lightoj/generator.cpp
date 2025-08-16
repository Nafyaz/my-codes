#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    freopen("in.txt", "w", stdout);

    ll T = 1, n = 16, i, x, y;

    cout << T << "\n";
    while(T--)
    {
        cout << n << "\n";

        x = 0;
        y = 0;
        for(i = 0; i < n; i++)
        {
            cout << x << " " << y << "\n";
            x++;
            y += x;
        }
    }
}