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

struct problem
{
    LL x, t, diff, id;
};
problem p[MAXN];

bool cmp(problem p1, problem p2)
{
    return (p1.t < p2.t);
}

void solve(int caseno, LL k)
{
    LL n, i, pos;
    vector<vector<LL>> ans;
    vector<LL> dp;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> p[i].t;
    for(i = 1; i <= n; i++)
        cin >> p[i].x;
    for(i = 1; i <= n; i++)
    {
        p[i].id = i;
        p[i].diff = p[i].x - p[i].t;
    }

    sort(p+1, p+n+1, cmp);

    for(i = 1; i <= n; i++)
    {   
        pos = lower_bound(dp.begin(), dp.end(), p[i].diff) - dp.begin();
        if(pos == dp.size())
        {
            dp.push_back(p[i].diff);
            ans.push_back(vector<LL>());
            ans.back().push_back(p[i].id);
        }
        else
        {
            dp[pos] = p[i].diff;
            ans[pos].push_back(p[i].id);
        }
    }

    cout << ans.size() << " " << (k==2) << "\n";
    if(k == 2)
    {
        for(i = 0; i < ans.size(); i++)
        {
            cout << ans[i].size() << " ";
            for(auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, k, caseno = 0;

    cin >> T >> k;

    while(T--)
    {
        solve(++caseno, k);
    }
}