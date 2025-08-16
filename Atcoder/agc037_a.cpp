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

    LL i, ans;
    string s;
    char prev;

    cin >> s;

    ans = 0;
    prev = 0;
    for(i = 0; i < s.size(); i++)
    {
        // show(i);
        // show(ans) << "\n";
        if(prev != s[i])
        {
            prev = s[i];
            ans++;
        }
        else
        {
            prev = 0;
            i++;
            ans++;
        }
    }

    if(i == s.size() + 1)
        ans--;
    
    cout << ans << "\n";
}