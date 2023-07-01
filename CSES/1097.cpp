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

LL x[5003], pref[5003];
LL dp[5003][5003];

LL call(LL bg, LL ed)
{
    if(bg == ed)
        return x[bg];

    if(dp[bg][ed] != -1)
        return dp[bg][ed];

    LL ret1 = pref[ed] - pref[bg-1] - call(bg, ed-1);
    LL ret2 = pref[ed] - pref[bg-1] - call(bg+1, ed);

    return dp[bg][ed] = max(ret1, ret2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> x[i];
        pref[i] = pref[i-1] + x[i];
    }

    memset(dp, -1, sizeof dp);
    cout << call(1, n) << "\n";
}