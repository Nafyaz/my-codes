#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[102][102];
string s;

ll call(ll st, ll ed)
{
    if(dp[st][ed] != -1)
        return dp[st][ed];

    if(st >= ed)
        return dp[st][ed] = 0;
    
    if(s[st] == s[ed])
        return dp[st][ed] = call(st+1, ed-1);

    return dp[st][ed] = min(call(st+1, ed), call(st, ed-1)) + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;

    cin >> T;

    while(T--)
    {
        cin >> s;

        memset(dp, -1, sizeof dp);
        cout << "Case " << ++caseno << ": " << call(0, s.size()-1) << "\n";
    }
}