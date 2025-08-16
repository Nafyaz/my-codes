#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int primes[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int valMask[60];
int n, a[102];
pii ans[102][200005];
int dp[102][200005];

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int i, j, val, mask, mask2, minMask;

    for(i = 1; i < 60; i++)
    {
        for(j = 0; j < 17; j++)
        {
            if(i%primes[j] == 0)
                valMask[i] |= (1 << j);
        }
    }

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i <= n; i++)
    {
        for(mask = 0; mask < 200005; mask++)
            dp[i][mask] = INT_MAX;
    }

    for(i = 1; i <= n; i++)
    {
        for(val = 1; val < 60; val++)
        {
            mask = (~valMask[val]) & ((1 << 17) - 1);
         

            for(mask2 = mask; ; mask2 = (mask2 - 1) & mask)
            {
                // if(mask2 < 100)
                // {
                //     show(i);
                //     show(val);
                //     show(mask);
                //     show(mask2) << "\n";
                // }

                if(dp[i][mask2 | valMask[val]] > abs(val - a[i]) + dp[i-1][mask2])
                {
                    dp[i][mask2 | valMask[val]] = abs(val - a[i]) + dp[i-1][mask2];
                    ans[i][mask2 | valMask[val]] = {val, mask2};
                }

                if(!mask2)
                    break;
            }
        }
    }


    minMask = 0;
    for(mask = 0; mask < 200005; mask++)
    {
        if(dp[n][mask] < dp[n][minMask])
            minMask = mask;
    }
    mask = minMask;


    stack<LL> stk;

    for(i = n; i >= 1; i--)
    {
        stk.push(ans[i][mask].ff);
        mask = ans[i][mask].ss;
    }

    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}