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

ll n;
pll marbles[3003];
ll dp[3003];

ll call(ll pos)
{
    if(pos == n)
        return 0;

    if(dp[pos] != -1)
        return dp[pos];

    ll i, ret = LLONG_MAX, total = 0;

    for(i = pos+1; i <= n; i++)
    {
        ret = min(ret, marbles[i].ss + total + call(i));
        total += marbles[i].ff - marbles[pos].ff;
    }

    return dp[pos] = ret;
}

void solve(int caseno)
{
    ll i;

    cin >> n;

    for(i = 0; i < n; i++)    
        cin >> marbles[i].ff >> marbles[i].ss;

    sort(marbles, marbles + n);
    marbles[n].ss = 0;

    // for(i = 0; i < n; i++)
    //     cout << marbles[i].ff << " " << marbles[i].ss << "\n";
    
    memset(dp, -1, sizeof dp);
    cout << marbles[0].ss + call(0) << "\n";
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