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

ll arr[3003], pref[3003]; 
ll dp[3003];

void solve(int caseno)
{
    ll n, i, j, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i]; 
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(pref[i] - pref[j] >= pref[j] - pref[dp[j]])
                dp[i] = j;
        }
    }

    // for(i = 0; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";

    ans = 0;
    for(i = n; i > 0; i = dp[i])
        ans++;

    cout << n - ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}