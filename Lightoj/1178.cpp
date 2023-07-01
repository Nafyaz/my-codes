#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    double a, b, c, d, s, Area;

    cin >> T;

    while(T--)
    {
        cin >> a >> b >> c >> d;

        if(a < c)
            swap(a, c);

        b = b/(1 - c/a);
        d = d/(1 - c/a);

        s = (a + b + d)/2;
        Area = sqrt(s*(s-a)*(s-b)*(s-d));

        cout << "Case " << ++caseno << ": ";
        cout << fixed << setprecision(7) << Area - Area/a/a*c*c << "\n";
    }
}