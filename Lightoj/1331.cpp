#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    double r1, r2, r3, c1, c2, c3;
    double a, b, c, s, A, B, C, triArea;

    cin >> T;

    while(T--)
    {
        cin >> r1 >> r2 >> r3;

        a = r2 + r3;
        b = r1 + r3;
        c = r1 + r2;
        s = (a+b+c)/2;

        A = acos((b*b + c*c - a*a)/2/b/c);
        B = acos((a*a + c*c - b*b)/2/a/c);
        C = acos((a*a + b*b - c*c)/2/a/b);

        triArea = sqrt(s*(s-a)*(s-b)*(s-c));

        c1 = A/2*r1*r1;
        c2 = B/2*r2*r2;
        c3 = C/2*r3*r3;

        cout << "Case " << ++caseno << ": " << fixed << setprecision(7) << triArea - c1 - c2 - c3 << "\n";
    }
}
