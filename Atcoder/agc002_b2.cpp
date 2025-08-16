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
#define MAXN 100005

bool isRed[MAXN];
LL cnt[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, ans, x, y;

    cin >> n >> m;

    isRed[1] = 1;
    for(i = 1; i <= n; i++)
        cnt[i] = 1;

    for(i = 0; i < m; i++)
    {
        cin >> x >> y;

        if(isRed[x])
            isRed[y] = 1;

        if(cnt[x] == 1)
            isRed[x] = 0;

        cnt[x]--;
        cnt[y]++;
    }

    ans = 0;
    for(i = 1; i <= n; i++)
        ans += isRed[i];

    cout << ans << "\n";
}