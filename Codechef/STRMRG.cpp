#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
char chA[5003], chB[5003];
ll dp[5003][5003][2];

ll call(ll i, ll j, ll lastTaken)
{    
    if(dp[i][j][lastTaken] != -1)
        return dp[i][j][lastTaken];

    if(i == n && j == m)
        return dp[i][j][lastTaken] = 0;

    char c;
    if(lastTaken)
        c = chB[j-1];
    else
        c = chA[i-1];

    if(i < n && chA[i] == c)
        return dp[i][j][lastTaken] = call(i+1, j, 0);
    if(j < m && chB[j] == c)
        return dp[i][j][lastTaken] = call(i, j+1, 1);

    if(i == n)
        return dp[i][j][lastTaken] = 1 + call(i, j+1, 1);
    if(j == m)
        return dp[i][j][lastTaken] = 1 + call(i+1, j, 0);

    ll ret = min(call(i+1, j, 0), call(i, j+1, 1));
    return dp[i][j][lastTaken] = ret + 1;
}

void solve()
{
    ll i, j;
    string a, b;

    cin >> n >> m >> a >> b;

    for(i = 0, j = -1; i < n; i++)
    {
        if(i == 0 || a[i] != a[i-1])
        {
            j++;
            chA[j] = a[i];
        }
    }
    n = j + 1;

    for(i = 0, j = -1; i < m; i++)
    {
        if(i == 0 || b[i] != b[i-1])
        {
            j++;
            chB[j] = b[i];
        }
    }
    m = j + 1;

    memset(dp, -1, sizeof dp);
    cout << 1 + min(call(1, 0, 0), call(0, 1, 1)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}