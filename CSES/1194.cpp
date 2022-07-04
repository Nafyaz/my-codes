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
ll mDist[1003][1003], aDist[1003][1003];
ll parent[1003][1003];

ll dirR[4] = {0, -1, 0, 1};
ll dirC[4] = {-1, 0, 1, 0};

bool isValid(pll node)
{
    return (node.ff >= 0 && node.ff < n && node.ss >= 0 && node.ss < m);
}

bool isInBoundary(pll node)
{
    return (node.ff == 0 || node.ff == n-1 || node.ss == 0 || node.ss == m-1);
}

void solve(ll caseno)
{
    cin >> n >> m;

    ll i, j;
    pll bg, ed, cur, nxt, dir;
    queue<pll> q;
    memset(mDist, -1, sizeof mDist);

    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == 'A')
                bg = {i, j};
            else if(grid[i][j] == 'M')
            {
                mDist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            nxt.ff = cur.ff + dirR[i];
            nxt.ss = cur.ss + dirC[i];

            if(isValid(nxt) && grid[nxt.ff][nxt.ss] != '#' && mDist[nxt.ff][nxt.ss] == -1)
            {
                mDist[nxt.ff][nxt.ss] = mDist[cur.ff][cur.ss] + 1;
                q.push(nxt);
            }
        }
    }


    ed = {-1, -1};
    memset(aDist, -1, sizeof aDist);

    aDist[bg.ff][bg.ss] = 0;
    q.push(bg);

    if(isInBoundary(bg))
        ed = bg;

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        if(ed.ff != -1)
            continue;

        for(i = 0; i < 4; i++)
        {
            nxt.ff = cur.ff + dirR[i];
            nxt.ss = cur.ss + dirC[i];

            if(isValid(nxt) && grid[nxt.ff][nxt.ss] != '#' && aDist[nxt.ff][nxt.ss] == -1 && (mDist[nxt.ff][nxt.ss] == -1 || mDist[nxt.ff][nxt.ss] > aDist[cur.ff][cur.ss] + 1))
            {
                aDist[nxt.ff][nxt.ss] = aDist[cur.ff][cur.ss] + 1;
                q.push(nxt);
                parent[nxt.ff][nxt.ss] = i;

                if(isInBoundary(nxt))
                    ed = nxt;
            }
        }
    }

    // for(i = 0; i < n; i++)
    // {
    //     for(j = 0; j < m; j++)
    //         cout << setw(2) << aDist[i][j] << " ";
    //     cout << "\n";
    // }

    if(ed.ff == -1)    
        cout << "NO\n";
    else
    {
        stack<char> stk;

        while(ed != bg)
        {
            switch (parent[ed.ff][ed.ss])
            {
                case  0:
                    stk.push('L');
                    break;
                case 1:
                    stk.push('U');
                    break;
                case 2:
                    stk.push('R');
                    break;
                case 3:
                    stk.push('D');
                    break;
            }

            dir = {dirR[parent[ed.ff][ed.ss]], dirC[parent[ed.ff][ed.ss]]};
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