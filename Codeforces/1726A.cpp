#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2003

int a[MAXN];

void solve(int caseno)
{
    int n, i, ans, mx, mn;

    cin >> n;

    mx = 0;
    mn = 10000;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        if(i != 0)
            mx = max(mx, a[i]);
        
        if(i != n-1)
            mn = min(mn, a[i]);
    }

    ans = max(mx - a[0], a[n-1] - mn);
    for(i = 0; i < n; i++)    
        ans = max(ans, a[i] - a[(i+1)%n]);
    
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