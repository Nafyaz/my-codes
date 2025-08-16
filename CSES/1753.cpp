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

vector<LL> KMP(string s)
{
    LL i, j, n = s.size();
    vector<LL> LPS(n);

    LPS[0] = 0;
    for(i = 1; i < n; i++)
    {
        j = LPS[i-1];

        while(j > 0 && s[i] != s[j])
            j = LPS[j-1];

        if(s[i] == s[j])
            j++;

        LPS[i] = j;
    }

    return LPS;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, ans;
    string s, t, total;

    cin >> s >> t;

    total = t + '#' + s;

    vector<LL> LPS = KMP(total);

    ans = 0;
    for(i = t.size(); i < total.size(); i++)
        ans += (LPS[i] == t.size());

    cout << ans << "\n";
}