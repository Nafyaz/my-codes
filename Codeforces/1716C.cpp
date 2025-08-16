#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int a[2][MAXN];
int dp1[2][MAXN], dp2[2][MAXN];

void solve(int caseno)
{
    int m, i;
    
    cin >> m;

    for(i = 0; i < m; i++)    
        cin >> a[0][i];
    for(i = 0; i < m; i++)
        cin >> a[1][i];

    dp1[0][m-1] = max(a[0][m-1] + 1, a[1][m-1]);
    dp1[1][m-1] = max(a[0][m-1], a[1][m-1] + 1);
    for(i = m-2; i >= 0; i--)
    {
        dp1[0][i] = max(max(a[0][i] + 1, dp1[0][i+1]) + 1, a[1][i]);
        dp1[1][i] = max(max(a[1][i] + 1, dp1[1][i+1]) + 1, a[0][i]);
    }

    cout << "dp1: \n";
    for(i = 0; i < m; i++)
        cout << dp1[0][i] << " ";
    cout << "\n";
    for(i = 0; i < m; i++)
        cout << dp1[1][i] << " ";
    cout << "\n";

    dp2[0][m-1] = dp1[0][m-1];
    dp2[1][m-1] = dp1[1][m-1];
    for(i = m-2; i >= 0; i--)
    {
        dp2[0][i] = min(dp1[0][i], max(max(max(a[0][i] + 1, a[1][i]) + 1, a[1][i+1]), dp2[1][i+1]));
        dp2[1][i] = min(dp1[1][i], max(max(max(a[1][i] + 1, a[0][i]) + 1, a[0][i+1]), dp2[0][i+1]));
    }

    cout << dp2[0][0] << "\n";
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