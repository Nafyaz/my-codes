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

int dirx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int diry[8] = {1, 0, -1, -1, -1, 0, 1, 1};
vector<pii> queenList;

bool isValid(pii pos)
{
    return (pos.ff >= 0 && pos.ff < 8 && pos.ss >= 0 && pos.ss < 8);
}

bool attackKing(pii king, pii queen)
{
    if(queen.ff == king.ff || queen.ss == king.ss)
        return 1;

    if(king.ff - queen.ff == king.ss - queen.ss)
        return 1;
    
    if(king.ff - queen.ff == queen.ss - king.ss)
        return 1;

    return 0;
}

bool kingLock(pii king)
{
    int i;
    pii newKing;
    bool flag;

    for(i = 0; i < 8; i++)
    {
        newKing = king;
        newKing.ff += dirx[i];
        newKing.ss += diry[i];

        if(isValid(newKing))
        {
            flag = 0;
            for(auto q : queenList)
            {
                if(attackKing(newKing, q))
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
                return 0;
        }
    }

    return 1;
}

void Print(pii king)
{
    int i, j, grid[8][8];

    memset(grid, 0, sizeof grid);

    grid[king.ff][king.ss] = 1;
    for(auto q : queenList)
        grid[q.ff][q.ss] = 2;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

void solve(int caseno)
{
    int i, j, i2, j2;
    pii king, queen1, queen2;

    cin >> king.ff >> king.ss;
    king.ff --;
    king.ss --;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            queen1 = make_pair(i, j);

            if(attackKing(king, queen1))
                continue;

            queenList.clear();
            queenList.push_back(queen1);

            if(kingLock(king))
            {
                Print(king);
                return;
            }
        }
    }

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            queen1 = make_pair(i, j);

            if(attackKing(king, queen1))
                continue;

            for(i2 = 0; i2 < 8; i2++)
            {
                for(j2 = 0; j2 < 8; j2++)
                {
                    queen2 = make_pair(i2, j2);

                    if(attackKing(king, queen2))
                        continue;

                    queenList.clear();
                    queenList.push_back(queen1);
                    queenList.push_back(queen2);

                    if(kingLock(king))
                    {
                        Print(king);
                        return;
                    }
                }
            }
        }
    }
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