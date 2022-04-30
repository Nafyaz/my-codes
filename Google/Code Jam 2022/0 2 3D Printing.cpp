#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, colors[4], mn[4], i, j, sum;

    cin >> T;

    while(T--)
    {
        for(i = 0; i < 4; i++)
            mn[i] = INT_MAX;

        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 4; j++)
            {
                cin >> colors[j];
                mn[j] = min(mn[j], colors[j]);
            }
        }

        sum = 1000000;
        if(mn[0]+mn[1]+mn[2]+mn[3] < sum)
            cout << "Case #" << ++caseno << ": IMPOSSIBLE\n";
        else
        {
            cout << "Case #" << ++caseno << ": ";

            for(i = 0; i < 4; i++)
            {
                cout << min(sum, mn[i]) << " ";
                sum -= min(sum, mn[i]);
            }
            cout << "\n";
        }
    }
}
