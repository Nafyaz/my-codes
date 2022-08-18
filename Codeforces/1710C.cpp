#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 200005

string s;
ll dp[MAXN][8][8];

bool check(int bits, int idx)
{
    if(bits&(1<<idx))
        return 1;
    return 0;
}

ll call(ll pos, ll isEqual, ll cond)
{
    if(pos >= s.size())
        return (cond == 7);

    if(dp[pos][isEqual][cond] != -1)
        return dp[pos][isEqual][cond];

    ll ret = 0, newIsEqual, newCond;
    for(int bits = 0; bits < 8; bits++)
    {
        if((isEqual&1) && s[pos] == '0' && (bits&1))
            continue;
        if((isEqual&2) && s[pos] == '0' && (bits&2))
            continue;
        if((isEqual&4) && s[pos] == '0' && (bits&4))
            continue;

        newIsEqual = isEqual;
        if(s[pos] != '0' + check(bits, 0))
            newIsEqual &= 6;
        if(s[pos] != '0' + check(bits, 1))
            newIsEqual &= 5;
        if(s[pos] != '0' + check(bits, 2))
            newIsEqual &= 3;

        bool aXorb = check(bits, 0) ^ check(bits, 1);
        bool aXorc = check(bits, 0) ^ check(bits, 2);
        bool bXorc = check(bits, 1) ^ check(bits, 2);

        newCond = cond;
        if(aXorb && aXorc)
            newCond |= 4;
        if(aXorb && bXorc)
            newCond |= 2;
        if(aXorc && bXorc)
            newCond |= 1;

        ret = (ret + call(pos+1, newIsEqual, newCond))%MOD;
    }

    return dp[pos][isEqual][cond] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, bits;

    cin >> s;

    memset(dp, -1, sizeof dp);
    cout << call(0, 7, 0);
}
 