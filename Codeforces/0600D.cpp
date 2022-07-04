#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006
#define EPS 1e-10
#define PI acos(-1)

void solve(ll caseno)
{
    long double x1, y1, r1;
    long double x2, y2, r2;
    long double d, theta1, theta2, c1, c2, t1, t2;
    long double ans;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    if(r1 < r2 + EPS)
    {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if(d + EPS > r1 + r2)
    {
        cout << "0\n";
        return;
    }

    if(r1 + EPS > d + r2)
    {
        cout << fixed << setprecision(20) << PI*r2*r2 << "\n";
        return;
    }

    theta1 = 2*acos((r1*r1 + d*d - r2*r2) / (2*r1*d));
    theta2 = 2*acos((r2*r2 + d*d - r1*r1) / (2*r2*d));

    c1 = theta1/2*r1*r1;
    c2 = theta2/2*r2*r2;

    t1 = abs(0.5*r1*r1*sin(theta1));
    t2 = abs(0.5*r2*r2*sin(theta2));

    if(r1*r1 + EPS > d*d + r2*r2)
        ans = c1-t1 + c2+t2;
    else
        ans = c1-t1 + c2-t2;

    cout << fixed << setprecision(20) << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}