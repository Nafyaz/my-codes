#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll dp[2][MAXN];

void solve(ll caseno)
{
    string s, t;
    ll i, k, n, A, B;

    cin >> s >> t >> k;

    n = s.size();

    A = B = 0;
    for(i = 0; i < n; i++)
    {
        if(s == t)
            A++;
        else
            B++;
        rotate(s.begin(), s.begin() + 1, s.end());
    }

    if(s == t)
        dp[0][0] = 1;
    else
        dp[1][0] = 1;

    for(i = 1; i <= k; i++)
    {
        dp[0][i] = (dp[0][i-1]*(A - 1) + dp[1][i-1]*A) % MOD;
        dp[1][i] = (dp[0][i-1]*B + dp[1][i-1]*(B-1)) % MOD;
    }

    cout << dp[0][k] << "\n";
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