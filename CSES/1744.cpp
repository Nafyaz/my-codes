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

LL dp[502][502];

LL call(LL a, LL b)
{
    if(a > b)
        swap(a, b);

    if(a == b)
        return dp[a][b] = 0;

    if(dp[a][b] != -1)
        return dp[a][b];

    LL i, ret = INF;

    for(i = 1; i < a; i++)
        ret = min(ret, call(i, b) + call(a-i, b) + 1);

    for(i = 1; i < b; i++)
        ret = min(ret, call(a, i) + call(a, b-i) + 1);

    return dp[a][b] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL a, b;

    cin >> a >> b;

    memset(dp, -1, sizeof dp);
    cout << call(a, b) << "\n";
}