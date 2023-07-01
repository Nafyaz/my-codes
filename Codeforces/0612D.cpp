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
#define MAXN 1000006

vector<pii> ans, segments;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i, j, l, r, cnt, minus;
    bool flag;
    
    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> l >> r;

        segments.push_back({l, 1});
        segments.push_back({r, -1});
    }

    sort(segments.begin(), segments.end());

    cnt = minus = 0;
    for(i = 0; i < segments.size();)
    {
        cnt -= minus;
        minus = 0;

        if(cnt >= k)
            flag = 1;
        else
            flag = 0;

        for(j = i; i < segments.size() && segments[i].ff == segments[j].ff; i++)
        {
            if(segments[i].ss == 1)
                cnt ++;
            else
                minus ++;
        }

        if(cnt >= k)
        {
            if(flag)
            {
                int bg = ans.back().ff;
                ans.pop_back();
                ans.push_back({bg, segments[j].ff});
            }
            else
            {
                ans.push_back({segments[j].ff, segments[j].ff});
            }
        }
        else if(flag && cnt == k-1)
        {
            int bg = ans.back().ff;
            ans.pop_back();
            ans.push_back({bg, segments[j].ff});        
        }
    }

    cout << ans.size() << "\n";
    for(auto [bg, ed] : ans)
        cout << bg << " " << ed << "\n";
}