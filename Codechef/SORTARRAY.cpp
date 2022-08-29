#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int n;
int arr[MAXN], nxt[MAXN], last[MAXN];
int dp[MAXN][2];

int call(int cur, bool prev)
{
    if(cur == n-1)
        return 0;

    if(dp[cur][prev] != -2)
        return dp[cur][prev];

    int ret1, ret2, ret = 2*n;

    if(arr[cur] <= arr[cur+1])
    {
        ret1 = call(cur+1, 0);
        if(ret1 != -1)
            ret = min(ret, ret1);
    }
    
    if(nxt[cur] != -1)
    {
        ret2 = call(nxt[cur], 1);
        if(ret2 != -1)
        {
            if(prev == 0)
                ret = min(ret, 1 + ret2);
            else
                ret = min(ret, ret2);
        }
    }

    if(ret == 2*n)
        return dp[cur][prev] = -1;
    else
        return dp[cur][prev] = ret;
}

void solve(int caseno)
{
    int i;

    cin >> n;

    for(i = 0; i <= n; i++)
    {
        nxt[i] = -1;
        last[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i][0] = dp[i][1] = -2;
    }

    for(i = n-1; i >= 0; i--)
    {
        nxt[i] = last[arr[i]];
        last[arr[i]] = i;
    }

    // for(i = 0; i < n; i++)
    //     cout << nxt[i]

    cout << call(0, 0) << "\n";
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