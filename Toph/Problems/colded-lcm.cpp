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

void solve(int caseno)
{
    LL L, R;
    LL g, x, y, ans;

    cin >> L >> R;

    ans = LLONG_MAX;
    for(g = 1; g < MAXN; g++)
    {
        x = (L + g - 1)/g;
        y = x+1;

        if(g*y <= R)
            ans = min(ans, g*x*y);
    }

    for(x = 1; x < MAXN; x++)
    {
        g = (L + x - 1)/x;
        y = x+1;

        if(g*y <= R)
            ans = min(ans, g*x*y);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}