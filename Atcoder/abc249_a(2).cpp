#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, e, f, x, q, dist1, dist2;

    cin >> a >> b >> c >> d >> e >> f >> x;

    q = x/(a+c);
    dist1 = b*q*a + b*min(x-q*(a+c), a);

    q = x/(d+f);
    dist2 = e*q*d + e*min(x-q*(d+f), d);

    if(dist1 > dist2)
        cout << "Takahashi\n";
    else if(dist1 < dist2)
        cout << "Aoki\n";
    else
        cout << "Draw\n";
}