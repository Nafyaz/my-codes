#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

LL dp[MAXN][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    LL i, n;

    cin >> s;

    // s = '#' + s;

    n = s.size();

    dp[0][1] = 1;   dp[0][2] = 0;
    for(i = 1; i < n; i++)
    {
        if(i >= 2)
            dp[i][1] = dp[i-1][2] + 1;

        if(s[i] != s[i-1])
            dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
        
        
        dp[i][2] = dp[i-2][1] + 1;

        cout << dp[i][1] << " " << dp[i][2] << "\n";
    }

    cout << max(dp[n-1][1], dp[n-1][2]) << "\n";
}