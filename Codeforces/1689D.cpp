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
pair<ll, pll> upperLeft, lowerLeft, upperRight, lowerRight;

ll calc(ll a, ll b)
{
    ll i, j, mx = 0;

    mx = max(mx, abs(upperLeft.ss.ff - a) + abs(upperLeft.ss.ss - b));
    mx = max(mx, abs(lowerLeft.ss.ff - a) + abs(lowerLeft.ss.ss - b));
    mx = max(mx, abs(upperRight.ss.ff - a) + abs(upperRight.ss.ss - b));
    mx = max(mx, abs(lowerRight.ss.ff - a) + abs(lowerRight.ss.ss - b));

    return mx;
}

void solve(ll caseno)
{
    ll i, j;
    ll val, ans, ansI, ansJ;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> grid[i];

    upperLeft = upperRight = {INT_MAX, {-1, -1}};
    lowerLeft = lowerRight = {INT_MIN, {-1, -1}};
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == 'B')
            {
                if(i+j < upperLeft.ff)                           
                    upperLeft = {i+j, {i, j}};
                if(i-j > lowerLeft.ff)
                    lowerLeft = {i-j, {i, j}};
                if(i-j < upperRight.ff)
                    upperRight = {i-j, {i, j}};
                if(i+j > lowerRight.ff)
                    lowerRight = {i+j, {i, j}};
            }
        }
    }

    // cout << upperLeft.ff << "; " << upperLeft.ss.ff << " " << upperLeft.ss.ss << "\n";
    // cout << lowerLeft.ff << "; " << lowerLeft.ss.ff << " " << lowerLeft.ss.ss << "\n";
    // cout << upperRight.ff << "; " << upperRight.ss.ff << " " << upperRight.ss.ss << "\n";
    // cout << lowerLeft.ff << "; " << lowerLeft.ss.ff << " " << lowerLeft.ss.ss << "\n";
    
    ans = INT_MAX;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            val = calc(i, j);
            if(val < ans)
            {
                ans = val;
                ansI = i;
                ansJ = j;
            }
        }
    }

    cout << ansI+1 << " " << ansJ+1 << "\n";
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