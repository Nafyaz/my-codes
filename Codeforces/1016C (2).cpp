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

LL a[2][MAXN], dp[2][MAXN];
LL sum[MAXN], pref[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[0][i];
    for(i = 0; i < n; i++)
        cin >> a[1][i];

    for(i = n-1; i >= 0; i--)
    {
        sum[i] = sum[i+1] + a[0][i] + a[1][i];

        pref[0][i] = pref[0][i+1] + sum[i+1] + (2*(n-i-1) + 1) * a[1][i];
        pref[1][i] = pref[1][i+1] + sum[i+1] + (2*(n-i-1) + 1) * a[0][i];
    }

    // cout << "sum: ";
    // for(i = 0; i < n; i++)
    //     cout << sum[i] << " ";
    // cout << "\n";

    // cout << "pref[0]: ";
    // for(i = 0; i < n; i++)
    //     cout << pref[0][i] << " ";
    // cout << "\n";

    // cout << "pref[1]: ";
    // for(i = 0; i < n; i++)
    //     cout << pref[1][i] << " ";
    // cout << "\n";

    for(i = n-1; i >= 0; i--)
    {
        dp[0][i] = max(pref[0][i], 2*sum[i+1] + dp[1][i+1] + a[1][i]);
        dp[1][i] = max(pref[1][i], 2*sum[i+1] + dp[0][i+1] + a[0][i]);
    }

    cout << dp[0][0] << "\n";
}