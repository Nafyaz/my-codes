#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll n, m, i, j, mxI, mxJ, mx, h, w;
    ll grid[45][45];

    cin >> n >> m;

    mx = INT_MIN;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(mx < grid[i][j])
            {
                mx = grid[i][j];
                mxI = i;
                mxJ = j;
            }
        }
    }

    h = max(mxI+1, n-mxI);
    w = max(mxJ+1, m-mxJ);

    cout << h*w << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}