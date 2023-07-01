#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 1003

ll n, m;
string grid[maxN];

ll calc(ll a, ll b)
{
    ll i, j, mx = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == 'B')
                mx = max(mx, abs(i-a) + abs(j-b));
        }
    }

    return mx;
}

void solve(ll caseno)
{
    ll i, j, left, right, up, down;
    ll avgI, avgJ;

    ll val, ans, ansI, ansJ;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> grid[i];

    if(caseno == 23)
    {
        for(i = 0; i < n; i++)
            cout << grid[i] << "\n";
    }

    // ans = INT_MAX;
    // for(i = 0; i < n; i++)
    // {
    //     for(j = 0; j < m; j++)
    //     {
    //         val = calc(i, j);
    //         if(val < ans)
    //             ans = val;
    //     }
    // }

    // cout << ans << "\n";
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