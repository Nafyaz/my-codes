#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll egcd(ll a, ll m, ll& x, ll& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

ll invmod(ll a, ll m)  //when gcd(a, m) = 1
{
    ll x, y;
    egcd(a, m, x, y);

    return (x%m + m) % m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, a, p, x, b, q, y, c, r, z, i, j, left, right, g, flag, ans;

    cin >> T;

    while(T--)
    {
        cin >> b >> q >> y;
        cin >> c >> r >> z;

        if(c < b || c+r*(z-1) > b+q*(y-1) || (z >= 2 && __gcd(c-b, r)%q != 0) || (z == 1 && (c-b)%q != 0))
        {
            cout << "0\n";
            continue;
        }

        flag = 1;
        ans = 0;
        for(i = 1; i*i <= r && flag; i++)
        {
            if(r%i == 0)
            {
                p = i;

                g = __gcd(p, q);
                if((c-b)%g != 0)
                {
                    flag = 1;
                    break;
                }
                left = invmod(p/g, q/g);
                if(c - b - left*p < q)
                {
                    flag = 1;
                    break;
                }

                ll cTemp = c+(z-1)*r;
                if((b - cTemp)%g != 0)
                {
                    flag = 1;
                    break;
                }
                right = invmod(p/g, q/g);
                if(cTemp + )

                p = r/i;
            }
        }
    }
}