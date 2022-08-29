#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

LL snukes[MAXN][6];
LL dp[MAXN][6];

LL call(LL T, LL X)
{
    if(T == MAXN)
        return 0;

    if(dp[T][X] != -1)
        return dp[T][X];

    LL ret = call(T+1, X);

    if(X != 0)
        ret = max(ret, call(T+1, X-1));
    if(X != 4)
        ret = max(ret, call(T+1, X+1));

    return dp[T][X] = ret + snukes[T][X];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, t, x, a;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> t >> x >> a;

        snukes[t][x] += a;
    }

    // for(i = 0; i < 6; i++)
    // {
    //     for(int j = 0; j < 6; j++)
    //         cout << snukes[i][j] << "         ";
    //     cout << "\n";
    // }

    memset(dp, -1, sizeof dp);
    cout << call(0, 0) << "\n";
}