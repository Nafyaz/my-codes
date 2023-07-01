#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<int, int> pLL;
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

int call(int pos, int mask)
{
    if(pos == n)
        return 0;

    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    int val, ret = INT_MAX;
    for(val = 1; val < 60; val++)
    {
        if(mask & valMask[val])
            continue;

        if(ret > abs(val - a[pos]) + call(pos+1, mask | valMask[val]))
        {
            ret = abs(val - a[pos]) + call(pos+1, mask | valMask[val]);
            ans[pos][mask] = {val, mask | valMask[val]};
        }
    }

    return dp[pos][mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, mask;

    for(i = 1; i < 60; i++)
    {
        for(j = 0; j < 17; j++)
        {
            if(i%primes[j] == 0)
                valMask[i] |= (1 << j);
        }
        // cout << i << ": " << valMask[i] << "\n";
    }
    // return 0;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    call(0, 0);

    for(i = 0, mask = 0; i < n; i++)
    {
        cout << ans[i][mask].ff << " ";
        mask = ans[i][mask].ss;
    }
}