#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll cost[15][15];
ll dp[20000];

ll call(ll mask)
{
    if(dp[mask] != -1)
        return dp[mask];

    ll i = __builtin_popcountll(mask), j, k;
    if(i == n)
        return 0;

    ll ret = INT_MAX, costHere;
    for(j = 0; j < n; j++)
    {
        if(mask & (1 << j))
            continue;

        costHere = cost[j][j];
        for(k = 0; k < n; k++)
        {
            if(mask & (1 << k))
            {
                costHere += cost[j][k];
            }
        }
        costHere += call(mask | (1 << j));

        ret = min(ret, costHere);
    }

    return dp[mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i, j;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cin >> cost[i][j];
        }

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(0) << "\n";
    }
}