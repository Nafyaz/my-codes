#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

int n, id;
string s;
int trie[MAXN][26];
bool endPoint[MAXN];
int dp[5003];

void Add(string t)
{
    int i, r = 0;
    for(i = 0; i < t.size(); i++)
    {
        if(trie[r][t[i] - 'a'] == 0)
            trie[r][t[i] - 'a'] = ++id;

        r = trie[r][t[i] - 'a'];
    }

    endPoint[r] = 1;
}

int call(int pos)
{
    if(pos == n)
        return 1;

    if(dp[pos] != -1)
        return dp[pos];

    int i, r = 0, ret = 0;

    for(i = pos; i < n; i++)
    {
        r = trie[r][s[i] - 'a'];
        
        if(r == 0)
            break;

        if(endPoint[r] == 1)
            ret = (ret + call(i+1)) % MOD;
    }

    return dp[pos] = ret;
}

void solve(int caseno)
{
    int i, k;
    string t;

    cin >> s;
    n = s.size();

    cin >> k;
    while(k--)
    {
        cin >> t;

        Add(t);
    }

    memset(dp, -1, sizeof dp);
    cout << call(0) << "\n";
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