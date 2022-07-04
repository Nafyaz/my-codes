#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 5003

string s;
ll dp[MAXN][MAXN];

void solve(ll caseno)
{
    ll n, i, j, ans;
    char c;

    cin >> n;

    s = "";
    for(i = 0; i < n; i++)
    {
        cin >> c;
        s.push_back(c);
    }

    dp[0][0] = 1;
    for(i = 1; i < n; i++)
    {
        if(s[i-1] == 'f')
        {
            for(j = 0; j < n; j++)
                dp[i][j+1] = dp[i-1][j];
        }
        else
        {
            for(j = n-1; j >= 0; j--)                            
                dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % MOD;            
        }
    }

    ans = 0;
    for(j = 0; j < n; j++)
        ans = (ans + dp[n-1][j]) % MOD;
    
    cout << ans << "\n";
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