#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int n, m;
int a[11], b[11], c[11], d[11], e[11];
int dp[11][1003];

int call(int type, int dough)
{
    if(type > m)
        return 0;

    if(dp[type][dough] != -1)
        return dp[type][dough];

    int i, ret = 0;
    for(i = 0; i <= e[type] && dough + i*c[type] <= n; i++)
        ret = max(ret, i*d[type] + call(type+1, dough + i*c[type]));

    return dp[type][dough] = ret;
}

void solve(int caseno)
{
    int i;

    a[0] = 1;
    b[0] = 0;
    e[0] = 1003;
    cin >> n >> m >> c[0] >> d[0];

    for(i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        e[i] = a[i] / b[i];
    }

    memset(dp, -1, sizeof dp);
    cout << call(0, 0) << "\n";
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