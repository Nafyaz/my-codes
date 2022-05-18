#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, dp[35][2][2];
ll call(ll currBit, bool prevBit, bool isSmall)
{

    if(dp[currBit][prevBit][isSmall] != -1)
        return dp[currBit][prevBit][isSmall];

    if(currBit == 0)
    {
        if(prevBit == 0)
            return dp[currBit][prevBit][isSmall] = 0;
        else if(isSmall || (n&1))        
            return dp[currBit][prevBit][isSmall] = 1;
        else
            return dp[currBit][prevBit][isSmall] = 0;
    }

    ll ret1, ret2;

    ret1 = call(currBit-1, 0, isSmall | (n & (1LL<<currBit)));
    ret2 = 0;

    if(isSmall || (n & (1LL<<currBit)))    
    {
        ret2 = call(currBit-1, 1, isSmall);
        if(prevBit)
        {
            if(isSmall)
                ret2 += (1LL << currBit);
            else
                ret2 += (n & ((1LL << currBit) -1)) + 1;
        }
    }
    
    return dp[currBit][prevBit][isSmall] = ret1 + ret2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i;

    cin >> T;
    while(T--)
    {
        cin >> n;
        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(32, 0, 0) << "\n";
        // for(i = 0; i < 3; i++)
        // {
        //     cout << "i : " << i << "\n";
        //     cout << dp[i][0][0] << " " << dp[i][0][1] << "\n";
        //     cout << dp[i][1][0] << " " << dp[i][1][1] << "\n\n";
        // }

    }
}