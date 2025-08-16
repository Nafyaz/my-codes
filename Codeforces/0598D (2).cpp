#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int n, m;
string grid[1009];
int c, color[1009][1009];
unordered_map<int, int> ans;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    if(color[x][y] == c)
        return;

    color[x][y] = c;

    int i, nextX, nextY;

    for(i = 0; i < 4; i++)
    {
        nextX = x + dirx[i];
        nextY = y + diry[i];
        if(grid[nextX][nextY] != '*')       
            dfs(nextX, nextY);        
        else
            ans[color[x][y]]++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, i, x, y;
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
        cin >> grid[i];

    for(i = 0; i < k; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        
        if(!color[x][y])
        {
            c++;
            dfs(x, y);
        }

        cout << ans[color[x][y]] << "\n";
    }
}
