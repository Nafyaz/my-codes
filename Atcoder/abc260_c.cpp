#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll dp[2][12];
void solve(int caseno)
{
    ll n, x, y, i;

    cin >> n >> x >> y;

    dp[0][1] = 0;
    dp[1][1] = 1;
    for(i = 2; i <= n; i++)
    {
        dp[1][i] = dp[0][i-1] + y*dp[1][i-1];
        dp[0][i] = dp[0][i-1] + x*dp[1][i];
    }

    cout << dp[0][n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}