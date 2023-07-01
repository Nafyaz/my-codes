// https://www.youtube.com/watch?v=pMEYMYTX-r0&ab_channel=KartikArora
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
#define MAXN 1000006

LL dp[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, n, T;

    dp[0][1] = dp[1][1] = 1;

    for(i = 2; i < MAXN; i++)
    {
        dp[0][i] = (2*dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + 4*dp[1][i-1]) % MOD;
    }

    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << (dp[0][n] + dp[1][n]) % MOD << "\n";
    }
}