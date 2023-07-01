#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)
#define show(x) cout << #x << ": " << x << "; "

struct point
{
    double x, y;
    
    point(double x_ = 0, double y_ = 0){x = x_; y = y_;}
};

void solve()
{
    double r, x;

    cin >> r >> x;

    x = x*PI/180;

    point G(0, r), H(0, 0), B(r, 0), C, N, D, I;

    double BC = 2*r*cos(x), BN = 2*r*cos(x/2);

    // show(BC);
    // show(BN);
    // cout << "\n";
    
    C.x = r - BC*cos(x);
    C.y = BC*sin(x);

    // show(C.x);
    // show(C.y);
    // cout << "\n";

    N.x = r - BN*cos(x/2);
    N.y = BN*sin(x/2);

    // show(N.x);
    // show(N.y);
    // cout << "\n";

    D.x = (B.x + C.x)/2;
    D.y = (B.y + C.y)/2;

    // show(D.x);
    // show(D.y);
    // cout << "\n";

    I.x = 0;
    // I.y = D.y + N.y * D.x / (-N.x + D.x);
    I.y = (N.y*D.x + D.y*(-N.x))/ (D.x - N.x);

    // show(I.x);
    // show(I.y);
    // cout << "\n";

    cout << fixed << setprecision(6) << sqrt((I.x-H.x)*(I.x-H.x) + (I.y-H.y)*(I.y-H.y)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;
    
    while(T--)
    {
        solve();
    }
}