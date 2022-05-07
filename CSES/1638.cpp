#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n;
string grid[1003];
ll dp[1003][1003];

ll call(ll i, ll j)
{
    if(i < 0 || i >= n || j < 0 || j >= n)
        return 0;
    if(grid[i][j] == '*')
        return dp[i][j] = 0;
    if(!i && !j)
        return dp[i][j] = 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = (call(i-1, j) + call(i, j-1)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i;

    cin >> n;
    for(i = 0; i < n; i++)    
        cin >> grid[i];
    
    memset(dp, -1, sizeof dp);
    cout << call(n-1, n-1);
}