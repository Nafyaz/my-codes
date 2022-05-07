#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n, a[25][25];
ll dp[25][3000006];

ll call(ll pos, ll mask)
{
    if(pos == n)
        return 1;

    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    ll i, ret = 0;
    for(i = 0; i < n; i++)
    {
        if(a[pos][i] && (mask & (1LL << i)) == 0)
            ret = (ret + call(pos+1, mask | (1LL << i))) % mod;
    }

    return dp[pos][mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << call(0, 0);
}