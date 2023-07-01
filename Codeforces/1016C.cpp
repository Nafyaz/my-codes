#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

LL a[2][MAXN];
LL dp[2][MAXN];
LL sum[MAXN];

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL n, i, k, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[0][i];
    for(i = 1; i <= n; i++)
        cin >> a[1][i];

    for(i = n; i >= 1; i--)
        sum[i] = sum[i+1] + a[0][i] + a[1][i];

    // for(i = 1; i <= n; i++)
    //     cout << sum[i] << " ";
    // cout << "\n";

    k = 0;
    for(i = 1; i <= n; i++)
    {
        if(i % 2)
        {
            dp[0][i] = dp[0][i-1] + k*a[0][i];
            k++;

            dp[1][i] = dp[0][i] + k*a[1][i];
            k++;
        }
        else
        {
            dp[1][i] = dp[1][i-1] + k*a[1][i];
            k++;

            dp[0][i] = dp[1][i] + k*a[0][i];
            k++;
        }
    }

    // for(i = 1; i <= n; i++)
    //     cout << dp[0][i] << " ";
    // cout << "\n";
    // for(i = 1; i <= n; i++)
    //     cout << dp[1][i] << " ";
    // cout << "\n";

    if(n%2)
        ans = dp[0][n];
    else
        ans = dp[1][n];
    for(i = n; i >= 1; i--)
    {
        if(i%2)
        {
            dp[0][i] = 2*(i-1)*a[0][i] + (2*(i-1) + 1)*a[0][i+1] + dp[0][i+2] - 2*sum[i+2] + (2*n-2)*a[1][i+1] + (2*n-1)*a[1][i];
            ans = max(ans, dp[0][i-1] + dp[0][i]);
        }
        else
        {
            dp[1][i] = 2*(i-1)*a[1][i] + (2*(i-1) + 1)*a[1][i+1] + dp[1][i+2] - 2*sum[i+2] + (2*n-2)*a[0][i+1] + (2*n-1)*a[0][i];
            ans = max(ans, dp[1][i-1] + dp[1][i]);
        }
    }

    cout << ans << "\n";
}