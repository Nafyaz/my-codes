#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll groupSize[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, p, op, healthy;

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
        healthy = 0;
        for(i = 0; i <= n && groupSize[i]; i++)
        {
            op++;
            if(healthy)
                healthy--;
            healthy += groupSize[i]-1;
        }

        op += (healthy+1)/2;

        cout << op << "\n";
    }
}
