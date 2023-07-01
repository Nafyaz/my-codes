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

LL grid[502][502], Log[502];
LL sparse[502][502][12];

LL query(LL r, LL ci, LL cj)
{
    LL k = Log[cj - ci + 1];

    return max(sparse[r][ci][k], sparse[r][cj - (1<<k) + 1][k]);
}

void solve(int caseno)
{
    LL n, i, j, k, q;
    LL r, c, sz, ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            sparse[i][j][0] = grid[i][j];
        }

        for(k = 1; k < 12; k++)
        {
            for(j = 0; j + (1<<k) - 1 < n; j++)
                sparse[i][j][k] = max(sparse[i][j][k-1], sparse[i][j + (1<<(k-1))][k-1]);
        }
    }

    cout << "Case " << caseno << ":\n";
    while(q--)
    {
        cin >> r >> c >> sz;
        r--;
        c--;

        ans = 0;
        for(i = r; i < r+sz; i++)
            ans = max(ans, query(i, c, c+sz-1));
        
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    LL i;
    Log[1] = 0;
    for(i = 2; i < 502; i++)
        Log[i] = Log[i/2] + 1;   

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}