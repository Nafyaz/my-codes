#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, k, i, e, x, y;

    cin >> T;

    while (T--)
    {
        cin >> n >> k;

        cout << "Case #" << ++caseno << ": ";

        x = y = 0;

        for(i = 0; i < n; i++)
        {
            cin >> e;
            x += e;
            y += e*e;            
        }

        if((y-x*x)%2 != 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        if(x == 0 && y == 0)
            cout << "0\n";
        else if(k == 1)
        {
            if(x == 0 || (y-x*x)%(2*x) != 0)
                cout << "IMPOSSIBLE\n";
            else
                cout << (y-x*x)/(2*x) << "\n";
        }
        else
            cout << (y-x*x)/2-x+x*x << " " << 1-x << "\n";
    }
}