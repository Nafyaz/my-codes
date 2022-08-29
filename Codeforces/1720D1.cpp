#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 300005;

int arr[MAXN];
int dp[MAXN];

bool check(int x, int y)
{
    return (arr[x]^y) < (arr[y]^x);
}

void solve(int caseno)
{
    int n, i, j, ans;

    cin >> n;

    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];

        dp[i] = 1;
        for(j = i-1; j >= max(0, i-256); j--)
        {
            if(check(j, i))
                dp[i] = max(dp[i], dp[j]+1);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
