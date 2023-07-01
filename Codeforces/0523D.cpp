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

    LL n, k, i, s, m, ans;
    multiset<LL> ms;

    cin >> n >> k;

    for(i = 0; i < k; i++)
        ms.insert(0);

    for(i = 0; i < n; i++)
    {
        cin >> s >> m;

        ans = max(s, (*ms.begin())) + m;
        cout << ans << "\n";

        ms.erase(ms.begin());
        ms.insert(ans);
    }
}