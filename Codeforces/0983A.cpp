#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, p, q, b, g;

    cin >> n;

    while(n--)
    {
        cin >> p >> q >> b;

        g = __gcd(p, q);
        q /= g;

        g = b;
        while(1)
        {
            g = __gcd(g, q);
            if(g == 1)
                break;
            q /= g;
        }

        if(q > 1)
            cout << "Infinite\n";
        else
            cout << "Finite\n";
    }
}
