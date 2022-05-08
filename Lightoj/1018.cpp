#include<bits/stdc++.h>
using namespace std;

int n, x[20], y[20];
int dp[70004];

int call(int mask)
{
    if(dp[mask] != -1)
        return dp[mask];

    int remaining = n - __builtin_popcount(mask);
    // cout << mask << " " << remaining << "\n";
    if(remaining == 0)
        return dp[mask] = 0;
    else if(remaining <= 2)
        return dp[mask] = 1;

    int i, j, k, newMask, ret = n;
    for(i = 0; i < n; i++)
    {
        if(mask & (1 << i))
            continue;

        for(j = i+1; j < n; j++)
        {
            if(mask & (1 << j))
                continue;

            newMask = mask | (1 << i) | (1 << j);

            for(k = 0; k < n; k++)
            {
                if((y[i] - y[k])*(x[j] - x[k]) == (y[j] - y[k])*(x[i] - x[k]))
                    newMask |= (1 << k);
            }    

            ret = min(ret, 1 + call(newMask));
        }

        break;
    }

    return dp[mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, caseno = 0, i, j, k;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)    
            cin >> x[i] >> y[i];
        
        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(0) << "\n";
    }
}
