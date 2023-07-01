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

vector<LL> z_function(string s)
{
    LL i, l, r, n = s.size();
    vector<LL> Z(n);

    Z[0] = 0;
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r)
            Z[i] = min(r-i+1, Z[i-l]);
        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]])
            Z[i]++;

        if(i+Z[i] - 1 > r)
        {
            l = i;
            r = i+Z[i] - 1;
        }
    }

    return Z;
}

void solve(int caseno)
{
    LL i, ans;
    string s, t, x;

    cin >> s >> t;

    x = t + '#' + s;
    
    vector<LL> xZ = z_function(x);

    ans = 0;
    for(i = 0; i < xZ.size(); i++)
        ans += (xZ[i] == t.size());
    
    cout << "Case " << caseno << ": " << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}