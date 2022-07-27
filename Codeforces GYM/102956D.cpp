#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll f[MAXN], dp[MAXN];
ll last[64];

void solve(int caseno)
{
    ll n, i, j, ans;

    cin >> n;

    memset(last, -1, sizeof last);
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> f[i];

        for(j = 0; j < 64; j++)
        {
            if(last[j] != -1)
                dp[i] = max(dp[i], dp[last[j]] + (f[last[j]] & f[i]));
        }

        ans = max(ans, dp[i]);
        last[64 - __builtin_clzll(f[i])] = i;
    }

    cout << ans << "\n";
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