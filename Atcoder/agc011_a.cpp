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

LL T[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, c, k, i, bg, init, ans;

    cin >> n >> c >> k;

    for(i = 0; i < n; i++)
        cin >> T[i];

    sort(T, T+n);

    ans = 0;
    for(i = 0, init = -INF, bg = -1; i < n; i++)
    {
        if(T[i] > init + k || i - bg + 1 > c)
        {
            ans++;
            init = T[i];
            bg = i;
        }
    }

    cout << ans << "\n";
}