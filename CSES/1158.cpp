#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll h[1003], s[1003];
ll dp[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, i, j;

    cin >> n >> x;

    for(i = 1; i <= n; i++)
        cin >> h[i];
    for(i = 1; i <= n; i++)
        cin >> s[i];

    for(i = 1; i <= n; i++)
    {
        for(j = x; j >= 0; j--)
        {
            if(j >= h[i])
                dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
        }
    }

    cout << dp[x];   
}