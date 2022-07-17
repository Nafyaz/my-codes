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

int n, dp[MAXN][2];
ll base = 31;
ll p[MAXN], Hash[MAXN];
string s;

bool call(int pos, bool single)
{
    if(pos == n)
        return 1;

    if(dp[pos][single] != -1)
        return dp[pos][single];

    if(single && call(pos+1, 0))
        return dp[pos][single] = 1;

    if(pos)
    {        
        if(2*pos > s.size() || Hash[2*pos] != (Hash[pos]*p[pos] + Hash[pos])%MOD)
            return dp[pos][single] = 0;
        return dp[pos][single] = call(2*pos, 1);
    }

    return dp[pos][single] = 0;
}

void solve(int caseno)
{
    int i;

    cin >> n >> s;

    for(i = 1; i <= s.size(); i++)
        Hash[i] = (Hash[i-1]*base + (s[i-1] - 'a' + 1)) % MOD;

    for(i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;

    cout << (call(0, 1)? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    p[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p[i] = (p[i-1] * base) % MOD;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}