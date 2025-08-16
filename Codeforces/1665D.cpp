#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
//    freopen("in.txt", "r", stdin);
    ll T, x, a, b, i, g;

    cin >> T;

    while(T--)
    {
        x = 0;
        a = 1;
        b = 3;
        for(i = 1; i <= 30; i++)
        {
            cout << "? " << a-x << " " << b-x << endl;
            cin >> g;

            if(g%(2*a) == 0)
                x += a;

            a *= 2;
            b *= 2;
        }

        cout << "! " << x << endl;
    }
}
