#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 5003

ll dp[MAXN][MAXN];

void solve(ll caseno)
{
    ll n, m, i, j, ans;
    string A, B;

    cin >> n >> m >> A >> B;

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(A[i-1] == B[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);;

            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]) - 1);

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
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