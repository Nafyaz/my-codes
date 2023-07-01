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

    string s, curr;
    LL i, ans;

    cin >> s;

    ans = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(curr == "" || curr[0] != s[i])
            curr = "";

        curr.push_back(s[i]);

        if(ans < curr.size())
            ans = curr.size();
    }

    cout << ans << "\n";
}