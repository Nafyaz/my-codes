#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

LL n;
vector<LL> col[502];
string grid[502];
bool vis[502][502];
LL dirX[4] = {0, 0, 1, -1};
LL dirY[4] = {1, -1, 0, 0};

bool isOk(LL x, LL y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(LL x, LL y)
{
    vis[x][y] = 1;

    for(LL i = 0; i < 4; i++)
    {
        LL x2 = x + dirX[i];
        LL y2 = y + dirY[i];
        if(isOk(x2, y2) && grid[x2][y2] == '#' && !vis[x2][y2])
            dfs(x2, y2);
    }
}

bool check()
{
    LL i, j, cnt;
    for(i = 0; i < n; i++)
    {
        grid[i] = string(n, '.');
        fill(vis[i], vis[i] + n, 0);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
            grid[i][col[i][j]] = '#';
    }

    cnt = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == '#' && !vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    return (cnt == n);
}

void Print()
{
    LL i;

    for(i = 0; i < n; i++)
        cout << grid[i] << "\n";

    cout << "\n";
    exit(0);
}

void call(LL r)
{
    if(r == n && check())
    {
        Print();
    }

    LL i, j, k;

    for(i = 0; i < n; i++)
    {
        if(col[i].size() == 3)
            continue;
        col[i].push_back(r);

        for(j = i+1; j < n; j++)
        {
            if(col[j].size() == 3)
                continue;
            col[j].push_back(r);

            for(k = j+1; k < n; k++)
            {
                if(col[k].size() == 3)
                    continue;
                col[k].push_back(r);

                call(r+1);

                col[k].pop_back();
            }

            col[j].pop_back();
        }

        col[i].pop_back();
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    freopen("out.txt", "w", stdout);

    LL i, j;

    cin >> n;

    call(0);
}