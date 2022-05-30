#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; ";

ll m, n;
ll mat[80][80], pref[80][80];
ll F[80][80][80][80];
bool vis[80][80][80][80];

ll findMin(ll x1, ll y1, ll x2, ll y2)
{
    if(vis[x1][y1][x2][y2])
        return F[x1][y1][x2][y2];

    if(x1 > x2 || y1 > y2)
        return LLONG_MAX;

    vis[x1][y1][x2][y2] = 1;

    if(x1 == x2 && y1 == y2)
        return F[x1][y1][x2][y2] = mat[x1][y1];

    ll right = findMin(x1, y1+1, x2, y2);
    ll left = findMin(x1, y1, x2, y2-1);
    ll bottom = findMin(x1+1, y1, x2, y2);
    ll top = findMin(x1, y1, x2-1, y2);
    ll S = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];

    // show(x1);
    // show(y1);
    // show(x2);
    // show(y2);

    // show(bottom);
    // show(top);
    // show(right);
    // show(left);
    // show(S);
    // cout << "\n";

    // cout << min({bottom, top, right, left, S}) << "\n";

    return F[x1][y1][x2][y2] = min({bottom, top, right, left, S});
}

void solve()
{
    ll i, j, ans = LLONG_MIN;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i][j];
            // cout << pref[i][j] << " ";
        }
        // cout << "\n";
    }

    memset(vis, 0, sizeof vis);
    // cout << findMin(2, 1, 4, 3);

    for(ll x1 = 1; x1+2 <= m; x1++)
    {
        for(ll y1 = 1; y1+2<= n; y1++)
        {
            for(ll x2 = x1+2; x2 <= m; x2++)
            {
                for(ll y2 = y1+2; y2 <= n; y2++)
                {
                    ll S = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
                    ans = max(ans, S - findMin(x1+1, y1+1, x2-1, y2-1));

                    // show(x1);
                    // show(y1);
                    // show(x2);
                    // show(y2);
                    // show(S);
                    // cout << findMin(x1+1, y1+1, x2-1, y2-1) << "\n";
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        cin >> m >> n;

        if(!m && !n)
            break;

        solve();
    }
}