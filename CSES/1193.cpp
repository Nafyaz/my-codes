#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n, m;
string grid[1003];
ll dist[1003][1003];
ll dirR[4] = {0, -1, 0, 1};
ll dirC[4] = {-1, 0, 1, 0};
ll parent[1003][1003];

bool isValid(pll cell)
{
    return (cell.ff >= 0 && cell.ff < n && cell.ss >= 0 && cell.ss < m);
}

void bfs(pll bg, pll ed)
{
    ll i;
    pll cur, nxt;
    queue<pll> q;
    q.push(bg);
    dist[bg.ff][bg.ss] = 0;

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            nxt.ff = cur.ff + dirR[i];
            nxt.ss = cur.ss + dirC[i];

            if(isValid(nxt) && grid[nxt.ff][nxt.ss] != '#' && dist[nxt.ff][nxt.ss] == -1)
            {
                q.push(nxt);
                dist[nxt.ff][nxt.ss] = dist[cur.ff][cur.ss] + 1;
                parent[nxt.ff][nxt.ss] = i;
            }
        }
    }
}

void solve(ll caseno)
{
    ll i, j;
    pll bg, ed;
    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == 'A')
                bg = {i, j};
            else if(grid[i][j] == 'B')
                ed = {i, j};
        }
    }
    
    memset(dist, -1, sizeof dist);
    bfs(bg, ed);

    if(dist[ed.ff][ed.ss] == -1)
        cout << "NO\n";
    else
    {
        stack<char> stk;
        while(ed != bg)
        {
            // cout << ed.ff << " " << ed.ss << ": ";
            // cout << parent[ed.ff][ed.ss] << "\n";

            switch (parent[ed.ff][ed.ss])
            {
            case 0:                
                stk.push('L');
                break;
            case 1:
                stk.push('U');
                break;
            case 2:
                stk.push('R');
                break;
            default:
                stk.push('D');
                break;
            }

            pll dir = {dirR[parent[ed.ff][ed.ss]], dirC[parent[ed.ff][ed.ss]]};
            ed.ff -= dir.ff;
            ed.ss -= dir.ss;
        }

        cout << "YES\n";
        cout << stk.size() << "\n";
        while(!stk.empty())
        {
            cout << stk.top();
            stk.pop();
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}