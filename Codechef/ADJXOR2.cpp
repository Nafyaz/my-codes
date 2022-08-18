#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll dp[MAXN][2];

void solve(int caseno)
{
    ll n, x, i, curr, prev;

    cin >> n >> x;

    cin >> curr;

    dp[0][0] = dp[0][1] = 0;
    prev = curr;

    for(i = 1; i < n; i++)
    {
        cin >> curr;

        dp[i][0] = max(dp[i-1][0] + (prev^curr), dp[i-1][1] + ((prev+x)^curr));
        dp[i][1] = max(dp[i-1][0] + (prev^(curr+x)), dp[i-1][1] + ((prev+x)^(curr+x)));

        prev = curr;
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << "\n";

//    for(i = 0; i < n; i++)
//        cout << dp[i][0] << " " << dp[i][1] << "\n";
//    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

