#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

LL n;
LL h[202], dp[40004][202][3];

LL call(LL a, LL b, LL pos, LL prevCol)
{
    
    if(pos == n+1)
        return 0;

    if(dp[a][pos][prevCol] != -1)
        return dp[a][pos][prevCol];


    LL ret1, ret2;
    ret1 = ret2 = INT_MAX;

    if(a >= h[pos])
    {
        
        if(prevCol == 1)
            ret1 = min(h[pos-1], h[pos]) + call(a-h[pos], b, pos+1, 0);
        else
            ret1 = call(a-h[pos], b, pos+1, 0);
        
        // if(a == 1 && b == 0 && pos == 3 && prevCol == 1)
        // {
        //     show(h[pos-1]);
        //     show(h[pos]);
        //     show(ret1);
        //     show(ret2);
        //     cout << "\n";
        // }
    }

    if(b >= h[pos])
    {
        if(prevCol == 0)
            ret2 = min(h[pos-1], h[pos]) + call(a, b-h[pos], pos+1, 1);
        else
            ret2 = call(a, b-h[pos], pos+1, 1);
    }

    // show(a);
    // show(b);
    // show(pos);
    // show(prevCol);
    // show(ret1);
    // show(ret2);
    // cout << "\n";

    return dp[a][pos][prevCol] = min(ret1, ret2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL i, a, b, ans;

    cin >> n >> a >> b;

    for(i = 1; i <= n; i++)
        cin >> h[i];

    memset(dp, -1, sizeof dp);
    ans = call(a, b, 1, 2);

    if(ans == INT_MAX)
        cout << "-1\n";
    else
        cout << ans << "\n";
}