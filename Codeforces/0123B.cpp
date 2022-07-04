#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll a, b, x1, y1, x2, y2;
    ll p1, p2, q1, q2;

    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    p1 = x1 + y1;
    if(p1 >= 0)
        p1 /= (2*a);
    else
        p1 = -(-p1 + 2*a - 1) / (2*a);
    p2 = x2 + y2;
    if(p2 >= 0)
        p2 /= (2*a);
    else
        p2 = -(-p2 + 2*a - 1) / (2*a);
    // p = abs(((x1 + y1) - (x2 + y2))/(2*a));

    q1 = y1 - x1;
    if(q1 >= 0)
        q1 /= (2*b);
    else
        q1 = -(-q1 + 2*b - 1) / (2*b);
    q2 = y2 - x2;
    if(q2 >= 0)
        q2 /= (2*b);
    else
        q2 = -(-q2 + 2*b - 1) / (2*b);
    // q = abs(((y1 - x1) - (y2 - x2))/(2*b));

    cout << max(abs(p1 - p2), abs(q1 - q2)) << "\n";
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