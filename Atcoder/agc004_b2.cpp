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
#define MAXN 2003

LL a[MAXN], b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, x, i, j, cost, ans;

    cin >> n >> x;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = INF;
    }

    ans = INF;
    for(j = 0; j < n; j++)
    {
        cost = x*j;
        for(i = 0; i < n; i++)
        {
            b[i] = min(b[i], a[(i-j+n)%n]);
            cost += b[i];
        }

        ans = min(ans, cost);
    }

    cout << ans << "\n";
}