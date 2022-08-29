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
int arr[MAXN];
vector<int> pos[MAXN];
int dp[MAXN];

int call(int cur)
{
    if(cur >= n)
        return 0;

    if(dp[cur] != -2)
        return dp[cur];

    int ret1, ret2, ret = 2*n;

    if(cur == n-1 || arr[cur] <= arr[cur+1])
    {
        ret1 = call(cur+1);
        if(ret1 != -1)
            ret = min(ret, ret1);
    }
    
    for(auto p : pos[arr[cur]])
    {
        if(p > cur && call(p) != -1)
            ret = min(ret, call(p) + 1);
    }

    if(ret == 2*n)
        return dp[cur] = -1;
    else
        return dp[cur] = ret;
}

void solve(int caseno)
{
    int i;

    cin >> n;

    for(i = 0; i <= n; i++)
        pos[i].clear();

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
        dp[i] = -2;
    }

    // for(i = 0; i < n; i++)
    //     cout << nxt[i]

    cout << call(0) << "\n";
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