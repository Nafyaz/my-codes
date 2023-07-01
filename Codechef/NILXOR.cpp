#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

int n, x;
int dp[32][2];

int call(int pos, bool isEqual)
{
    if(pos < 0)
        return (isEqual == 0);

    if(dp[pos][isEqual] != -1)
        return dp[pos][isEqual];

    if((x&(1<<pos)) != 0)
        return dp[pos][isEqual] = call(pos-1, isEqual);

    int ret;
    ret = call(pos-1, isEqual);

    if((n&(1<<pos)) != 0)
        ret += call(pos-1, 0);
    else if(isEqual == 0)
        ret += call(pos-1, 0);

    return dp[pos][isEqual] = ret;
}

void solve(int caseno)
{
    cin >> n >> x;

    memset(dp, -1, sizeof dp);
    cout << call(30, 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
