#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2003

LL m, d;
LL dp[MAXN][2][MAXN];

LL call(string &s, LL pos, bool isSmaller, LL rem)
{
    if(pos == s.size())    
        return (rem == 0);
    
    if(dp[pos][isSmaller][rem] != -1)
        return dp[pos][isSmaller][rem];

    LL ret = 0;
    for(LL i = 0; i <= 9; i++)
    {
        if(pos%2 == 1 && i != d)
            continue;
        if(pos%2 == 0 && i == d)
            continue;

        if(isSmaller == 1)
            ret = (ret + call(s, pos+1, 1, (rem*10 + i)%m)) % MOD;
        else if(s[pos] == '0' + i)
            ret = (ret + call(s, pos+1, 0, (rem*10 + i)%m)) % MOD;
        else if(s[pos] > '0' + i)
            ret = (ret + call(s, pos+1, 1, (rem*10 + i)%m)) % MOD;
    }

    return dp[pos][isSmaller][rem] = ret;
}

LL isValid(string s)
{
    LL rem = 0, i;
    
    for(i = 0; i < s.size(); i++)
    {
        if(i%2 == 1 && s[i] != '0' + d)
            return 0;
        if(i%2 == 0 && s[i] == '0' + d)
            return 0;

        rem = (10*rem + s[i] - '0')%m;
    }

    return (rem == 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL low, high;
    string a, b;

    cin >> m >> d;
    cin >> a >> b;

    memset(dp, -1, sizeof dp);
    high = call(b, 0, 0, 0);

    memset(dp, -1, sizeof dp);
    low = call(a, 0, 0, 0);

    cout << ((high - low + isValid(a)) % MOD + MOD) % MOD << "\n";
}