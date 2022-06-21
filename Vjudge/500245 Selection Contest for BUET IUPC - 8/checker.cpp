#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

string s, t;
ll dp[5000][5000];

ll calc(ll i, ll j)
{
    // show(i);
    // show(j);
    // show(s);
    // show(t);
    // cout << "\n";

    if(j == t.size())
        return dp[i][j] = 1;
    if(i == s.size())
        return dp[i][j] = 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    ll ret = 0;
    for(ll k = i; k < s.size(); k++)
    {
        if(s[k] == t[j])
            ret += calc(k+1, j+1);
    }

    return dp[i][j] = ret;
}

void solve(ll caseno)
{
    ll i, j, sum = 0, v;
    cin >> s;

    t = "nunhehheh";

    // memset(dp, -1, sizeof dp);
    // cout << calc(0, 0) << "\n";

    while(1)
    {
        t.push_back('a');

        memset(dp, -1, sizeof dp);
        v = calc(0, 0);

        // show(s);
        // show(t);
        // show(v);
        // cout << "\n";

        if(!v)
            break;

        sum += v;
    }

    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);

    ll T = 1, caseno = 0;

     cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
