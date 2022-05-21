#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n;
ll mat[80][80], pref[80][80];

void solve()
{
    ll i, j;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i][j];
        }
    }
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