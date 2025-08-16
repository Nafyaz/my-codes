#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, ans;

    cin >> n >> m;

    ans = min(n, m/2);

    n -= ans;
    m -= 2*ans;

    ans += m/4;

    cout << ans << "\n";
}