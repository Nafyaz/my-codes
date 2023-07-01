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

    LL n, i, p, ans;
    vector<pLL> v;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> p;
        v.push_back({p, i});
    }

    sort(v.begin(), v.end());

    ans = 0;
    for(i = 1; i < n; i++)
        ans += abs(v[i].ss - v[i-1].ss);

    cout << ans << "\n";
}