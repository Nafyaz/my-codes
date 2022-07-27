#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll pos2age[1503][1503];
pll age2pos[2250006];
ll rows[1503], columns[1503];

void solve(ll caseno)
{
    ll n, i, j, ans, youngerInRow, youngerInColumn;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> pos2age[i][j];
            age2pos[pos2age[i][j]] = {i, j};
        }
    }

    ans = 0;
    for(i = 1; i <= n*n; i++)
    {
        youngerInRow = rows[age2pos[i].ff];
        youngerInColumn = columns[age2pos[i].ss];

        ans += youngerInRow*(n-1- youngerInColumn) + youngerInColumn*(n-1-youngerInRow);

        rows[age2pos[i].ff]++;
        columns[age2pos[i].ss]++;
    }

    cout << ans/2 << "\n";
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