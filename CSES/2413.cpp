#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dp[1000006];
ll pref[2][1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i;

    dp[0] = 1;
    pref[0][1] = pref[1][1] = 1;
    for(i = 1; i < 1000006; i++)
    {
        dp[i] = pref[1][i];
        dp[i] = (dp[i] + )
    }

    cin >> T;

    while(T--)
    {
        cin >> n;
        
        cout << dp[n] << "\n";
    }
}