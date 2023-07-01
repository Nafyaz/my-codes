#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i;
    string s, t, ans;
    char c;
    set<char> rem;

    for(c = 'a'; c <= 'z'; c++)
        rem.insert(c);

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        auto it = rem.lower_bound(s[i] + 1);
        if(it == rem.end())
        {
            t.push_back(s[i]);
            rem.erase(s[i]);
            continue;
        }

        c = *it;
        ans = t + c;

        t.push_back(s[i]);
        rem.erase(s[i]);
    }

    if(!rem.empty())
        cout << s + *rem.begin() << "\n";
    else if(ans == "")
        cout << "-1\n";
    else
        cout << ans << "\n";
}