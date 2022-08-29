#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool vis[45][725];
bool grid[45][725];

bool bfs()
{
    int rad, ang;
    queue<pii> q;

    for(ang = 0; ang < 720; ang++)    
    {
        q.push({0, ang});
        vis[0][ang] = 1;
    }
    
    while(!q.empty())
    {
        rad = q.front().ff;
        ang = q.front().ss;

        if(rad > 40)
            return 1;

        q.pop();

        if(rad > 0 && !vis[rad-1][ang] && grid[rad-1][ang] == 0)
        {
            q.push({rad-1, ang});
            vis[rad-1][ang] = 1;
        }

        if(!vis[rad+1][ang] && grid[rad+1][ang] == 0)
        {
            q.push({rad+1, ang});
            vis[rad+1][ang] = 1;
        }

        if(!vis[rad][(ang+1)%720] && grid[rad][(ang+1)%720] == 0)
        {
            q.push({rad, (ang+1)%720});
            vis[rad][(ang+1)%720] = 1;
        }

        if(!vis[rad][(ang+719)%720] && grid[rad][(ang+719)%720] == 0)
        {
            q.push({rad, (ang+719)%720});
            vis[rad][(ang+719)%720] = 1;
        }
    }

    return 0;
}

void solve(int caseno)
{
    int n, i;
    string type;
    int r, theta1, theta2;
    int r1, r2, theta;

    memset(vis, 0, sizeof vis);
    memset(grid, 0, sizeof grid);

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> type;

        if(type == "C")
        {
            cin >> r >> theta1 >> theta2;
            
            for(theta = theta1; theta != theta2; theta = (theta + 1)%360)
            {
                grid[2*r][2*theta] = 1;
                grid[2*r][2*theta + 1] = 1;
            }
            grid[2*r][2*theta2] = 1;
        }
        else
        {
            cin >> r1 >> r2 >> theta;
            
            for(r = r1; r != r2; r++)
            {
                grid[2*r][2*theta] = 1;
                grid[2*r + 1][2*theta] = 1;
            }
            grid[2*r2][2*theta] = 1;
        }
    }

    cout << (bfs()? "YES\n" : "NO\n");
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