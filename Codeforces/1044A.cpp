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

vector<int> v, h;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, x1, x2, y, ans, good, bad;

    cin >> n >> m;

    v.resize(n);
    for(i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for(i = 0; i < m; i++)
    {
        cin >> x1 >> x2 >> y;
        
        if(x1 == 1)
            h.push_back(x2);
    }

    sort(h.begin(), h.end());

    good = lower_bound(h.begin(), h.end(), 1000000000) - h.begin();
    bad = h.size() - good;
    ans = n + bad;
    for(i = 0; i < n; i++)    
    {
        good = lower_bound(h.begin(), h.end(), v[i]) - h.begin();
        bad = h.size() - good;
        ans = min(ans, i + bad);
    }
    
    cout << ans << "\n";
}