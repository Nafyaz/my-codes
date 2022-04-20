#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll groupSize[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, p, op, mxPos, mxVal, nonZero;

    cin >> T;

    while(T--)
    {
        cin >> n;

        fill(groupSize, groupSize+n+1, 0);
        groupSize[0] = 1;

        for(i = 1; i < n; i++)
        {
            cin >> p;
            groupSize[p]++;
        }

        sort(groupSize, groupSize+n+1, greater<ll>());

        op = 0;
        for(i = 0; i <= n; i++)
        {
            if(groupSize[i])
            {
                op ++;
                groupSize[i] --;
            }
            else
            {
                nonZero = i;
                break;
            }
        }


        for(i = 0; i <= n; i++)
        {
            if(groupSize[i])
            {
                groupSize[i] = max(0LL, groupSize[i] - op + i + 1);
            }
            else
                break;
        }

//        cout << "op: " << op << "\n";
//        cout << "GroupSize:\n";
//        for(i = 0; i <= n; i++)
//        cout << groupSize[i] << " ";
//        cout << "\n";


        while(1)
        {
            sort(groupSize, groupSize+nonZero, greater<ll>());

            mxPos = -1;
            mxVal = 0;

            bool flag = 0;
            for(i = 0; i <= n && groupSize[i]; i++)
            {
                flag = 1;
                nonZero = i+1;

                groupSize[i]--;
                if(groupSize[i] > mxVal)
                {
                    mxVal = groupSize[i];
                    mxPos = i;
                }
            }

            if(flag)
                op++;

            if(mxPos >= 0)
                groupSize[mxPos]--;
            else
                break;

        }

        cout << op << "\n";
    }
}
