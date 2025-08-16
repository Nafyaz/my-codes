#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;

int p[1003];

void solve(int caseno)
{
    int n, i, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p+n);

    ans = 0;
    for(i = 0; i < n; i++)
    {
        if(i <= n/2)
            ans += p[i]/2;
        else
            ans += p[i];
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
