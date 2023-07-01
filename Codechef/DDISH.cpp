#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[11][2][1024];

ll call(ll pos, string S, bool isSmall, bool hasStarted, ll mask)
{
    if(isSmall && dp[pos][hasStarted][mask] != -1)
        return dp[pos][hasStarted][mask];

    if(pos == S.size())
    {
        if(isSmall)
            return dp[pos][hasStarted][mask] = 1;
        else
            return 1;
    }

    ll ret = 0;

    char ch = '9';
    if(!isSmall)
        ch = S[pos];

    for(char i = '0'; i <= ch; i++)
    {
        if(mask & (1 << (i-'0')))
            continue;

        if(i == '0' && !hasStarted)
            ret += call(pos+1, S, isSmall | (S[pos] > '0'), 0, mask);
        else        
            ret += call(pos+1, S, isSmall | (S[pos] > i), 1, mask | (1 << (i-'0')));        
    }

    if(isSmall)
        return dp[pos][hasStarted][mask] = ret;
    else
        return ret;
}

void solve()
{
    ll L, R, ans;

    cin >> L >> R;

    if(L > 9876543210LL)
    {
        cout << "0\n";
        return;
    }

    R = min(R, 9876543210LL);

    string strL, strR;
    strL = to_string(L-1);
    strL = string(10 - strL.size(), '0') + strL;
    strR = to_string(R);
    strR = string(10 - strR.size(), '0') + strR;

    // cout << strL << "; " << strR << endl;

    // memset(dp, -1, sizeof dp);
    ans = call(0, strR, 0, 0, 0); 

    // memset(dp, -1, sizeof dp);
    ans -= call(0, strL, 0, 0, 0);

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    memset(dp, -1, sizeof dp);

    cin >> T;

    while(T--)
    {
        solve();
    }
}