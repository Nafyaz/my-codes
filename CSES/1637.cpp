#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1000006];

ll call(ll n)
{
    if(!n)
        return 0;
    
    if(dp[n] != 0)
        return dp[n];

    ll temp = n, ret = INT_MAX;
    
    while(temp)
    {
        if(temp%10 != 0)
            ret = min(ret, 1+call(n - temp%10));
        temp /= 10;
    }

    return dp[n] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;
    cout << call(n);
}