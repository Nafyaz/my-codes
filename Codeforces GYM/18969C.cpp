#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define t first
#define x second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

struct problem
{
    LL x, t, id;
};
problem p[MAXN];

bool cmp(problem a, problem b)
{
    if(a.x-a.t == b.x-b.t)
        return a.t < b.t;
    return a.x-a.t > b.x-b.t;
}

void solve(int caseno, LL k)
{
    LL n, i, pos, low, high, mid;
    vector<vector<LL>> ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i].t;
    for(i = 0; i < n; i++)
        cin >> p[i].x;
    for(i = 0; i < n; i++)
        p[i].id = i+1;
    
    sort(p, p+n, cmp);

    // for(i = 0; i < n; i++)
    //     cout << p[i].id << " " << p[i].t << " " << p[i].x << "\n";

    for(i = 0; i < n; i++)
    {   
        low = 0;
        high = ans.size()-1;
        pos = ans.size();
        while(low <= high)
        {
            mid = (low + high)/2;

            if(p[ans[mid].back()].t <= p[i].t)
            {
                pos = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        if(pos == ans.size())
            ans.push_back(vector<LL>());

        ans[pos].push_back(i);
    }

    cout << ans.size() << " " << (k==2) << "\n";
    if(k == 2)
    {
        for(i = 0; i < ans.size(); i++)
        {
            cout << ans[i].size() << " ";
            for(auto u : ans[i])
                cout << p[u].id << " ";
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