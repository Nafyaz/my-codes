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

LL a[MAXN];

void solve(int caseno)
{
    LL n, i, mx = 0, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        mx = max(mx, a[i]);
    }

    if(n == 2)
    {
        cout << max(a[0] + a[1], 2*abs(a[0] - a[1])) << "\n";
        return;
    }

    if(n >= 4)
    {
        cout << mx*n << "\n";
        return;
    }

    if(a[0] == mx || a[2] == mx)
    {
        cout << mx*3 << "\n";
        return;
    }
    
    ans = a[0] + a[1] + a[2];
    ans = max(ans, 3*(mx - a[0]));
    ans = max(ans, 3*a[2]);
    ans = max(ans, 3*(mx - a[2]));
    ans = max(ans, 3*a[0]);
    ans = max(ans, 3*abs(a[2] - a[0]));
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    if(T == 1000)
    {

    }

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}