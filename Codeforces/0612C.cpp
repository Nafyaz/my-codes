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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, ans;
    string s;

    cin >> s;
    
    map<char, char> mp;
    mp['('] = ')';
    mp['{'] = '}';
    mp['['] = ']';
    mp['<'] = '>';

    stack<char> stk;

    ans = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(mp.find(s[i]) != mp.end())
            stk.push(mp[s[i]]);
        else if(stk.empty())
        {
            cout << "Impossible\n";
            return 0;   
        }
        else
        {
            ans += (s[i] != stk.top());
            stk.pop();
        }
    }

    if(!stk.empty())
        cout << "Impossible\n";
    else
        cout << ans << "\n";
}