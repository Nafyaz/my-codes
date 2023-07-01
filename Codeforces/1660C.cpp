#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll Next[26][200005];
ll lastSeen[26];
ll dp[200005];

ll call(ll i)
{
    if(i >= s.size())
        return 0;

    if(dp[i] != -1)
        return dp[i];

    ll ret1 = call(i+1);

    if(Next[s[i]-'a'][i] == -1)
        return dp[i] = ret1;

    ll ret2 = 2 + call(Next[s[i]-'a'][i]+1);

    return dp[i] = max(ret1, ret2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j;

    cin >> T;

    while(T--)
    {
        cin >> s;

        memset(lastSeen, -1, sizeof lastSeen);

        for(i = 0; i < s.size(); i++)
        {
            dp[i] = -1;
            for(j = 0; j < 26; j++)
                Next[j][i] = -1;
        }

        for(i = 0; i < s.size(); i++)
        {
            if(lastSeen[s[i]-'a'] != -1)
                Next[s[i]-'a'][lastSeen[s[i]-'a']] = i;

            lastSeen[s[i]-'a'] = i;
        }

//        for(i = 0; i < 26; i++)
//        {
//            cout << (char)('a'+i) << ": ";
//            for(j = 0; j < s.size(); j++)
//                cout << Next[i][j] << " ";
//            cout << "\n";
//        }

        cout << s.size() - call(0) << "\n";
    }
}
