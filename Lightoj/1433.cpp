#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    pair<double, double> O, A, B;
    double AB, r, theta;

    cin >> T;

    while(T--)
    {
        cin >> O.ff >> O.ss >> A.ff >> A.ss >> B.ff >> B.ss;

        AB = sqrt((A.ff-B.ff)*(A.ff-B.ff) + (A.ss-B.ss)*(A.ss-B.ss));
        r = sqrt((O.ff-A.ff)*(O.ff-A.ff) + (O.ss-A.ss)*(O.ss-A.ss));
        theta = acos((2*r*r - AB*AB) / (2*r*r));

        cout << "Case " << ++caseno << ": " << fixed << setprecision(6) << r*theta << "\n";
    }
}
