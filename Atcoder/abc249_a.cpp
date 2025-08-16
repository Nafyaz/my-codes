#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, e, f, x, y, dist1 = 0, dist2 = 0;

    cin >> a >> b >> c >> d >> e >> f >> x;

    y = x;

    while(x)
    {
        dist1 += b*min(x, a);
        x -= min(x, a);

        x -= min(x, c);
    }

    while(y)
    {
        dist2 += e*min(y, d);
        y -= min(y, d);

        y -= min(y, f);
    }

    if(dist1 > dist2)
        cout << "Takahashi\n";
    else if(dist1 < dist2)
        cout << "Aoki\n";
    else
        cout << "Draw\n";
}

