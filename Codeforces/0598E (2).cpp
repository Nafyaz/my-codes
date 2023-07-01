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

int dp[32][32][52];

int call(int n, int m, int k)
{
    if(n > m)
        swap(n, m);

    if(k == 0 || n*m == k)
        return dp[n][m][k] = 0;

    if(dp[n][m][k] != -1)
        return dp[n][m][k];

    int i, j, ret = INT_MAX, cost;
    for(i = 1; 2*i <= n; i++)
    {
        cost = m*m;

        for(j = 0; j <= k; j++)
        {
            if(j > i*m || k-j > (n-i)*m)
                continue;

            ret = min(ret, cost + call(i, m, j) + call(n-i, m, k-j));
        }
    }

    for(i = 1; 2*i <= m; i++)
    {
        cost = n*n;

        for(j = 0; j <= k; j++)
        {
            if(j > i*n || k-j > (m-i)*n)
                continue;

            ret = min(ret, cost + call(i, n, j) + call(m-i, n, k-j));
        }
    }

    return dp[n][m][k] = ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0, n, m, k;

    cin >> T;

    memset(dp, -1, sizeof dp);
    call(30, 30, 50);
    while(T--)
    {
        cin >> n >> m >> k;

        if(n > m)
            swap(n, m);

        cout << dp[n][m][k] << "\n";
    }
}