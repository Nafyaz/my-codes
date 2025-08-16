#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

LL n, i, j, x, y;
LL dp[102][102];

LL call(LL bgIdx, LL edIdx)
{
    LL len = edIdx - bgIdx + 1;
    LL bgNum = n - len + 1;

    if(dp[bgIdx][edIdx] != -1)
        return dp[bgIdx][edIdx];

    if(bgNum == x)
    {
        if(bgIdx == i)
        {
            if(bgIdx == edIdx)
                return dp[bgIdx][edIdx] = 1;
            else
                return dp[bgIdx][edIdx] = call(bgIdx + 1, edIdx);
        }
        else if(edIdx == i)
        {
            if(bgIdx == edIdx)
                return dp[bgIdx][edIdx] = 1;
            else
                return dp[bgIdx][edIdx] = call(bgIdx, edIdx - 1);
        }
        else
            return dp[bgIdx][edIdx] = 0;
    }

    if(bgNum == y)
    {
        if(bgIdx == j)
        {
            if(bgIdx == edIdx)
                return dp[bgIdx][edIdx] = 1;
            else
                return dp[bgIdx][edIdx] = call(bgIdx + 1, edIdx);
        }
        else if(edIdx == j)
        {
            if(bgIdx == edIdx)
                return dp[bgIdx][edIdx] = 1;
            else
                return dp[bgIdx][edIdx] = call(bgIdx, edIdx - 1);
        }
        else
            return dp[bgIdx][edIdx] = 0;
    }

    if(bgIdx == edIdx)
    {
        if(bgIdx != 1 && bgIdx != n)
            return dp[bgIdx][edIdx] = 1;
        else
            return dp[bgIdx][edIdx] = 0;
    }

    return dp[bgIdx][edIdx] = (call(bgIdx + 1, edIdx) + call(bgIdx, edIdx - 1)) % MOD;
}

void solve(int caseno)
{
    cin >> n >> i >> j >> x >> y;

    if((i == 1 || i == n) && x == n)
    {
        cout << "0\n";
        return;
    }

    if((j == 1 || j == n) && y == n)
    {
        cout << "0\n";
        return;
    }

    memset(dp, -1, sizeof dp);
    cout << call(1, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}