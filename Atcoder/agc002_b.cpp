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
#define MAXN 200005

long double prob[MAXN];
LL cnt[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, i, ans, x, y;
    long double p;

    cin >> n >> m;

    prob[1] = 1;
    for(i = 1; i <= n; i++)
        cnt[i] = 1;

    for(i = 0; i < m; i++)
    {
        cin >> x >> y;

        p = prob[x]/cnt[x];

        prob[x] -= p;
        prob[y] += p;

        cnt[x]--;
        cnt[y]++;
    }

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        if(prob[i] > 1e-12)
            ans++;
    }

    cout << ans << "\n";
}