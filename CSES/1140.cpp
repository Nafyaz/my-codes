#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015LL
#define MOD 1000000007
#define MAXN 200005

LL n;
pair<pLL, LL> p[MAXN];
LL dp[MAXN];

LL call(LL pos)
{
    if(pos >= n)
        return 0;

    if(dp[pos] != -1)
        return dp[pos];

    LL nxtPos = lower_bound(p+pos, p+n, make_pair(make_pair(p[pos].ff.ss, INF), INF)) - p;

    return dp[pos] = max(call(pos+1), p[pos].ss + call(nxtPos));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i].ff.ff >> p[i].ff.ss >> p[i].ss;

    sort(p, p+n);

    memset(dp, -1, sizeof dp);
    cout << call(0) << "\n";
}