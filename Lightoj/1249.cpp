#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i, n, l, w, h, val, mnVal, mxVal;
    string name, mnName, mxName;

    cin >> T;

    while(T--)
    {
        cin >> n;

        mnVal = INT_MAX;
        mxVal = INT_MIN;

        for(i = 0; i < n; i++)
        {
            cin >> name >> l >> w >> h;

            val = l*w*h;

            if(val < mnVal)
            {
                mnVal = val;
                mnName = name;
            }
            if(val > mxVal)
            {
                mxVal = val;
                mxName = name;
            }
        }

        cout << "Case " << ++caseno << ": ";

        if(mxVal == mnVal)
            cout << "no thief\n";
        else
            cout << mxName << " took chocolate from " << mnName << "\n";
    }
}
