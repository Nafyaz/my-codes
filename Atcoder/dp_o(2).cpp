#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[25][25];
ll dp[3000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j, mask;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for(mask = 0; mask < (1LL << n); mask++)
    {
        i = __builtin_popcount(mask);
        for(j = 0)
    }
}