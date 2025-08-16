#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll dp[1003];
ll arr[1003], pref[1003];

void solve(int caseno)
{
    ll n, i, j;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];

        dp[i] = LLONG_MIN;
        for(j = 0; j < i; j++)        
            dp[i] = max(dp[i], dp[j] + (i-j)*(pref[i] - pref[j]));        
    }

    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}