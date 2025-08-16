#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll health[20];
ll damage[20][20];
ll dp[40004];

ll call(ll mask)
{
    if(dp[mask] != -1)
        return dp[mask];

    if(__builtin_popcountll(mask) == n)
        return dp[mask] = 0;

    ll i, j, ret = INT_MAX;
    for(i = 0; i < n; i++)
    {
        if((mask&(1LL << i)) == 0)
        {
            ret = min(ret, health[i] + call(mask|(1LL << i)));

            for(j = 0; j < n; j++)
            {
                if((mask&(1LL << j)) && damage[j][i])
                    ret = min(ret, (health[i] + damage[j][i] - 1)/damage[j][i] + call(mask|(1LL << i)));
            }
        }
    }

    return dp[mask] = ret;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T, caseno = 0, i, j;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)        
            cin >> health[i];
        
        string temp[20];
        for(i = 0; i < n; i++)
        {            
            cin >> temp[i];
            for(j = 0; j < n; j++)
                damage[i][j] = temp[i][j] - '0';
        }

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(0) << "\n";
    }
}