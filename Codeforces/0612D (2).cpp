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

vector<pLL> segments, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, k, l, r, i, cnt;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> l >> r;
        segments.push_back({l, -1});
        segments.push_back({r, 1});
    }

    sort(segments.begin(), segments.end());

    cnt = 0;
    for(i = 0; i < 2*n; i++)
    {
        cnt -= segments[i].ss;
        if(segments[i].ss == -1 && cnt == k)
            l = segments[i].ff;
        if(segments[i].ss == 1 && cnt == k-1)
            ans.push_back({l, segments[i].ff});
    }

    cout << ans.size() << "\n";
    for(auto [bg, ed] : ans)
        cout << bg << " " << ed << "\n";
}