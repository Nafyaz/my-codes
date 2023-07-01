#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<ll> pals;
ll dp[40004];

bool isPal(ll n)
{
    ll x = n, rev = 0;
    while(x)
    {
        rev = rev*10 + x%10;
        x /= 10;
    }

    return (rev == n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j;

    for(i = 0; i < 40004; i++)
    {
        if(isPal(i))
            pals.push_back(i);
    }

    dp[0] = 1;
    for(i = 0; i < pals.size(); i++)
    {
        for(j = 1; j < 40004; j++)
        {
            if(j >= pals[i])
                dp[j] = (dp[j] + dp[j-pals[i]]) % mod;
        }
    }

    // for(i = 0; i <= 12; i++)
    //     cout << dp[i] << " ";

    cin >> T;

    while(T--)
    {
        cin >> n;

        cout << dp[n] << "\n";
    }
}