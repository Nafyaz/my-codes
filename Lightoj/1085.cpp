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
#define MAXN 100005

pLL a[MAXN];
LL n, BIT[MAXN];

void Update(LL i, LL d)
{
    while(i <= n)
    {
        BIT[i] += d;
        BIT[i] %= MOD;
        i += i & (-i);
    }
}

LL Query(LL i)
{
    LL ret = 0;
    while(i > 0)
    {
        ret += BIT[i];
        ret %= MOD;
        i -= i & (-i);
    }

    return ret;
}

bool cmp(pLL x, pLL y)
{
    if(x.ff != y.ff)
        return x.ff < y.ff;
    
    return x.ss > y.ss;
}

void solve(int caseno)
{
    LL i, ans, q;

    cin >> n;

    for(i = 1; i <= n; i++)
        BIT[i] = 0;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i;
    }

    sort(a+1, a+n+1, cmp);

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        q = Query(a[i].ss);
        ans = (ans + q+1) % MOD;
        Update(a[i].ss, q+1);
    }

    cout << "Case " << caseno << ": " << ans << "\n";
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