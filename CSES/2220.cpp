#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

string s;
LL dp[20][2];

LL call(int pos, bool isSmaller, bool isLZ, int lastChar)
{
    if(pos == 20)
        return 0;

    if(dp[pos][isSmaller] != -1)
        return dp[pos][isSmaller];

    char c;
    LL ret = 0;

    for(c = '0'; c <= '9'; c++)
    {
        if(isSmaller)
        {
            if(c - 'a' != lastChar)
                ret += call(pos+1, 1, 0, c - '0');
        }
        else if(c <= s[pos])
        {
            if(isLZ && s[pos] == '0')
                ret += call(pos+1, )
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, ans;
    string a, b;

    cin >> a >> b;

    while(a.size() < 20)
        a = '0' + a;

    while(b.size() < 20)
        b = '0' + b;

    memset(dp, -1, sizeof dp);
    s = a;
    ans = call(0, 0);

    memset(dp, -1, sizeof dp);
    s = b;
    ans -= call(0, 0);
}