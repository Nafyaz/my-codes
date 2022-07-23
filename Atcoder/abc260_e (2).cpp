#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int arr[MAXN];
int to[MAXN];
int ans[MAXN];

void solve(int caseno)
{
    int n, m, i, x, y, yMin, xMax, bg, ed;

    cin >> n >> m;

    xMax = 1;
    yMin = m;
    for(i = 1; i <= n; i++)
    {
        cin >> x >> y;

        xMax = max(xMax, x);
        yMin = min(yMin, y);
        to[x] = max(to[x], y);
    }

    for(i = 1; i <= yMin; i++)
    {
        bg = xMax - i + 1;
        ed = m - i + 1;
        ans[bg] += 1;
        ans[ed+1] -= 1;

        xMax = max(xMax, to[i]);
    }

    for(i = 1; i <= m; i++)
    {
        ans[i] += ans[i-1];
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}