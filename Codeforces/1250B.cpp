#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll arr[8003];

void solve(ll caseno)
{
    ll n, k, t, i, j, ans, s, r;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> t;
        arr[t]++;
    }

    sort(arr+1, arr+k+1);

    ans = INT_MAX;
    for(i = 0; i <= k; i += 2)
    {
        s = 0;
        for(j = 1; j <= i/2; j++)        
            s = max(s, arr[j] + arr[i - j + 1]);
        for(j = i+1; j <= k; j++)
            s = max(s, arr[j]);

        ans = min(ans, s * (i/2 + k-i));
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}