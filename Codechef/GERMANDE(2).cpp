#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool d[1000006];
ll pref[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, o1, o2, n, i, j, winState, winDist, ans;

    cin >> T;

    while(T--)
    {
        cin >> o1 >> o2;
        n = o1 * o2;

        for(i = 1; i <= n; i++)
        {
            cin >> d[i];
            pref[i] = pref[i-1] + d[i];
        }

        ans = 0;
        for(i = 1; i <= o2; i++)
        {
            winState = 0;
            for(j = i; j+o2-1 <= n; j += o2)
            {                
                winDist = pref[j+o2-1] - pref[j-1];

                if(2*winDist > o2)
                    winState ++;
                
                // cout << "j: " << j << "; winState: " << winState << "; winDist: " << winDist << "\n";
            }

            winDist = pref[n] - pref[j-1] + pref[i-1];
            if(2*winDist > o2)
                winState ++;

            // cout << "winState: " << winState << "\n";
            if(2*winState > o1)
            {
                ans = 1;
                break;
            }
        }

        cout << ans << "\n";
    }
}