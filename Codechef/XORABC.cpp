#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll val(ll a, ll b, ll c)
{
    return (a^b) + (a^c) + (b^c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, x, a, b, c;

    cin >> T;

    while(T--)
    {
        cin >> x;

        if((x&1) || ((x&(x-1)) == 0))
        {
            cout << "-1\n";
            continue;
        }

        a = 0;
        for(b = 1; b <= x; b *= 2)
        {
            c = x/2;
            if(val(a, b, c) == x)
            {
                cout << a << " " << b << " " << c << "\n";
                break;
            }

            c = (x-b)/2;
            if(val(a, b, c) == x)
            {
                cout << a << " " << b << " " << c << "\n";
                break;
            }
        }
    }
}
