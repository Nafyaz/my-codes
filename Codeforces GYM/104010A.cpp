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

    int n, m, days, ans;

    cin >> n >> m;

    if(n > m)
        cout << (n+m)/2 << "\n";
    else
    {
        days = m+14-n;
        ans = m+7;

        if(ans > days)
            ans -= days;

        cout << ans << "\n";
    }
}