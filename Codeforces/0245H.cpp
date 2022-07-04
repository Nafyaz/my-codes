#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool isPal[5003][5003];
ll dp[5003][5003];

void solve(ll caseno)
{
    ll i, j, len, q;
    string s;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        isPal[i][i] = 1;
        if(i > 0)
            isPal[i-1][i] = (s[i-1] == s[i]);
    }

    for(len = 2; len <= s.size(); len++)
    {
        for(i = 0; i + len - 1 < s.size(); i++)
        {
            j = i + len - 1;
            if(isPal[i+1][j-1] == 1 && s[i] == s[j])
                isPal[i][j] = 1;
        }
    }

    // for(i = 0; i < s.size(); i++)
    // {
    //     for(j = 0; j < s.size(); j++)
    //         cout << isPal[i][j] << " ";
    //     cout << "\n";
    // }

    for(i = 0; i < s.size(); i++)
        dp[i][i] = 1;

    for(len = 2; len <= s.size(); len++)
    {
        for(i = 0; i + len - 1 < s.size(); i++)
        {
            j = i + len - 1;
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + isPal[i][j];
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> i >> j;

        cout << dp[i-1][j-1] << "\n"; 
    }
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