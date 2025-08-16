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

vector<LL> get_SA(string &s)
{
    LL i, len, cnt, n = s.size();

    vector<LL> prev(n), ret(n);
    vector<pair<pLL, LL>> curr(n);

    for(i = 0; i < n; i++)
        prev[i] = s[i];

    for(len = 2; len <= 2*n; len *= 2)
    {
        curr.clear();
        for(i = 0; i < n; i++)
        {
            if(i + len/2 >= n)
                curr.push_back({{prev[i], -1}, i});
            else
                curr.push_back({{prev[i], prev[i+len/2]}, i});
        }

        sort(curr.begin(), curr.end());

        for(i = 0, cnt = 0; i < n; i++)
        {
            if(i == 0 || curr[i].ff == curr[i-1].ff)
                prev[curr[i].ss] = cnt;
            else
                prev[curr[i].ss] = ++cnt;
        }
    }

    for(i = 0; i < n; i++)
        ret[prev[i]] = i;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n;
    string s, ans;

    while(getline(cin, s))
    {
        n = s.size();
        s = s + s;
        vector<LL> sa = get_SA(s);

        ans = "";
        for(LL i = 0; i < 2*n; i++)
        {
            if(sa[i] < n)
                ans.push_back(s[(sa[i] - 1 +n)%n]);
        }
        
        cout << ans << "\n";
    }
}