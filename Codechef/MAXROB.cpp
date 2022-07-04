#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll n, k;
ll arr[MAXN], dp[MAXN];

ll call(ll pos)
{
    if(pos >= n)    
        return 0;
    if(dp[pos] != -1)
        return dp[pos];

    return dp[pos] = max(call(pos+1), arr[pos] + call(pos + k + 1));
}

void solve(ll caseno)
{
    ll i;

    cin >> n >> k;

    for(i = 0; i < n; i++)    
    {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof dp);
    cout << call(0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}