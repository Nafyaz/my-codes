#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll dp[5003][5003];

void solve(ll caseno)
{
    ll i, j, n, m;
    string a, b;

    cin >> a >> b;

    n = a.size();
    m = b.size();

    for(i = 0; i <= n; i++)
        dp[i][0] = i;
    for(j = 0; j <= m; j++)
        dp[0][j] = j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            if(a[i-1] == b[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    cout << dp[n][m] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}