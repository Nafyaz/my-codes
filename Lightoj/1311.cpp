#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    double v1, v2, v3, a1, a2, t, d, birbDist;

    cin >> T;

    while(T--)
    {
        cin >> v1 >> v2 >> v3;
        cin >> a1 >> a2;

        d = v1*v1/2/a1 + v2*v2/2/a2;
        t = max(v1/a1, v2/a2);
        birbDist = v3*t;

        cout << "Case " << ++caseno << ": " << fixed << setprecision(6) << d << " " << birbDist << "\n";
    }
}
