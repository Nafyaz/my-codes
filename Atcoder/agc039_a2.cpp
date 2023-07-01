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

    string s;
    LL k, i, ans;
    LL pref, suff, prefEnd, suffEnd;
    bool allSame;

    cin >> s >> k;

    ans = 0;

    if(k == 1 || s[0] != s.back())
    {
        for(i = 0; i+1 < s.size(); i++)
        {
            if(s[i] == s[i+1])
            {
                ans += k;
                i++;
            }
        }

        cout << ans << "\n";
        return 0;
    }

    allSame = 1;
    for(i = 1; i < s.size(); i++)
        allSame &= (s[0] == s[i]);

    if(allSame)
    {
        cout << (s.size() * k)/2 << "\n";
        return 0;
    }

    pref = 0;
    for(i = 0; i < s.size() && s[i] == s[0]; i++)
        pref++;
    ans += pref/2;
    prefEnd = i;

    suff = 0;
    for(i = s.size()-1; i >= 0 & s[i] == s.back(); i--)
        suff++;
    ans += suff/2;
    suffEnd = i;
    
    for(i = prefEnd; i+1 <= suffEnd; i++)
    {
        if(s[i] == s[i+1])
        {
            ans += k;
            i++;
        }
    }

    ans += (pref + suff)/2 * (k-1);

    cout << ans << "\n";
}