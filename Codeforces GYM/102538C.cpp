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

int n, m;
string grid[3003];
bool p[3003][3003], vis[3003][3003];

bool isValid(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.')
        return 1;
    return 0;
}

bool dfs(int i, int j)
{
    if(!isValid(i, j))
        return 0;

    if(vis[i][j] == 1)
        return p[i][j];
    vis[i][j] = 1;
    
    if(i == n-1 && j == m-1)
    {
        p[i][j] = 1;
        return 1;
    }

    p[i][j] |= dfs(i+1, j);
    p[i][j] |= dfs(i, j+1);

    return p[i][j];
}

void getLeftMost(int i, int j)
{
    if(!isValid(i, j))
        return;

    
}

void solve(int caseno)
{
    int i, j;
    ll ans, empty;

    cin >> n >> m;

    empty = 0;
    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == '.')
                empty++;
        }
    }

    if(dfs(0, 0) == 0)
        cout << empty*(empty-1)/2 << "\n";

    getLeftMost(0, 0);
    getRightMost(0, 0);


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