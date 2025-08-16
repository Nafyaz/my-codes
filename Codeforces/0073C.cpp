#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

string s;
ll bonus[26][26];
ll dp[102][26][102];

ll call(ll pos, ll prev, ll remChange)
{
    if(pos == s.size())
        return 0;

    if(dp[pos][prev][remChange] != -1)
        return dp[pos][prev][remChange];

    ll ret = LLONG_MIN;
    for(ll i = 0; i < 26; i++)
    {
        if(s[pos] - 'a' == i)
            ret = max(ret, call(pos+1, i, remChange) + bonus[prev][i]);
        else if(remChange >= 1)
            ret = max(ret, call(pos+1, i, remChange-1) + bonus[prev][i]);
    }

    return dp[pos][prev][remChange] = ret;
}

void solve(int caseno)
{
    ll n, k, i, c, ans;
    string a, b;

    cin >> s >> k >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        bonus[a[0] - 'a'][b[0] - 'a'] = c;
    }

    memset(dp, -1, sizeof dp);

    ans = LLONG_MIN;
    for(i = 0; i < 26; i++)
    {
        if(s[0] - 'a' == i)
            ans = max(ans, call(1, i, k));
        else if(k >= 1)
            ans = max(ans, call(1, i, k-1));
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
