#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, ansPower, mxNegPower, isMxNegSet, mulPower, mulSign, l, r, lastzero, lastmxNeg;

    cin >> T;

    while(T--)
    {
        cin >> n;

        ansPower = 0;

        mxNegPower = 0;
        isMxNegSet = 0;

        mulPower = 0;
        mulSign = 1;

        l = 0;
        r = n;

        lastzero = -1;
        lastmxNeg = -1;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(a == 0)
            {
                mulPower = 0;
                mulSign = 1;

                mxNegPower = 0;
                isMxNegSet = 0;

                lastzero = i;

                continue;
            }

            if(a > 0)
                mulPower += (a == 2);
            else
            {
                mulPower += (a == -2);
                mulSign *= -1;
            }

            if(mulSign == -1 && (isMxNegSet == 0 || mxNegPower > mulPower))
            {
                isMxNegSet = 1;
                mxNegPower = mulPower;
                lastmxNeg = i;
            }

            if(mulSign == 1 && mulPower > ansPower)
            {
                ansPower = mulPower;
                l = lastzero + 1;
                r = n - i - 1;
            }

            if(mulSign == -1 && isMxNegSet && mulPower - mxNegPower > ansPower)
            {
                ansPower = mulPower - mxNegPower;
                l = lastmxNeg + 1;
                r = n - i - 1;
            }
        }

        cout << l << " " << r << "\n";
    }
}
