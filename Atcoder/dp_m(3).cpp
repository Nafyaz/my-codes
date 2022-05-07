#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll a[102];
ll dp[102][100005];

ll call(ll i, ll j)
{
    if(j < 0)
        return 0;

    if(!i && !j)
        return dp[i][j] = 1;
    else if(!j)
        return dp[i][j] = 1;
    else if(!i)
        return dp[i][j] = 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = ((call(i, j-1) + call(i-1, j) - call(i-1, j-a[i]-1)) % mod + mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K, i;

    cin >> N >> K;

    for(i = 1; i <= N; i++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    cout << call(N, K) << "\n";
}