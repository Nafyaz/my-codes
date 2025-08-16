#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 5003

ll n;
ll X[MAXN];
ll bonus[MAXN], dp[MAXN][MAXN];

ll call(ll toss, ll cnt)
{
    if(toss == n+1)
        return 0;

    if(dp[toss][cnt] != -1)
        return dp[toss][cnt];

    return dp[toss][cnt] = max(call(toss+1, 0), X[toss] + bonus[cnt+1] + call(toss+1, cnt+1));
}

void solve(int caseno)
{
    ll m, i, c, y;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
        cin >> X[i];

    for(i = 1; i <= m; i++)
    {
        cin >> c >> y;
        bonus[c] = y;
    }

    memset(dp, -1, sizeof dp);
    cout << call(1, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
