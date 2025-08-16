#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

string p, s;
LL dp[2][MAXN];

LL calc()
{
    memset(dp, 0, sizeof dp);

    LL i, j;

    for(i = 0; i <= p.size(); i++)
        dp[0][i] = 1;


    for(i = 0; i < s.size(); i++)
    {
        for(j = 0; j < p.size(); j++)
        {
            if(s[i] != p[j])
                dp[1][j+1] = dp[1][j];
            else
                dp[1][j+1] = (dp[1][j] + dp[0][j]) % MOD;
        }

        swap(dp[0], dp[1]);
        memset(dp[1], 0, sizeof dp[1]);
    }

    return dp[0][p.size()];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, ans;
    set<string> st;

    cin >> p >> s;

    ans = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(st.find(s) != st.end())
            continue;

        st.insert(s);
        ans = (ans + calc()) % MOD;

        rotate(s.begin(), s.begin() + 1, s.end());
    }

    cout << ans << "\n";
}