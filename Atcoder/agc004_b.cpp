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
#define MAXN 2003

LL n, a[MAXN], sparse[MAXN][20], Log[MAXN];

LL query(LL l, LL r)
{
    LL k, ret1, ret2;

    if(l <= r)
    {
        k = Log[r-l+1];
        return min(sparse[l][k], sparse[r-(1<<k)+1][k]);
    }

    k = Log[r+1];
    ret1 = min(sparse[0][k], sparse[r-(1<<k)+1][k]);
    k = Log[n-1-l+1];
    ret2 = min(sparse[l][k], sparse[n-1-(1<<k)+1][k]);

    // for(LL i = 0; i < 4; i++)
    //     cout << Log[i] << " ";
    // cout << "\n\n";

    // for(LL j = 0; j <= 2; j++)
    // {
    //     for(LL i = 0; i < n; i++)
    //         cout << sparse[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";

    return min(ret1, ret2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL x, i, j, cost, ans;

    for(i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;

    cin >> n >> x;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        sparse[i][0] = a[i];
    }

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1<<j) - 1< n; i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
    }

    // cout << query(n-1, 0) << "\n\n";

    // return 0;

    ans = INF;
    for(j = 0; j < n; j++)
    {
        cost = x*j;
        for(i = 0; i < n; i++)
            cost += query((i-j+n)%n, i);

        // show(j);
        // show(cost) << "\n";

        ans = min(ans, cost);
    }

    cout << ans << "\n";
}