#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll dirx[4] = {-1, 1, 0, 0};
ll diry[4] = {0, 0, 1, -1};
string grid[12];
stack<ll> stk;   

bool isOk(ll r, ll c)
{
    if(r >= 0 && r < 12 && c >= 0 && c < 12 && grid[r][c] != '#')
        return 1;
    return 0;
}

bool call(ll r, ll c, ll dir)
{
    if(grid[r][c] == '*')
    {
        return 1;
    }

    grid[r][c] = '#';

    ll i, r2, c2;
    for(i = 0; i < 4; i++)
    {
        r2 = r + dirx[i];
        c2 = c + diry[i];

        if(isOk(r2, c2) && call(r2, c2, i))
        {
            stk.push(i);
            return 1;
        }
    }

    return 0;
}

void init()
{
    for(ll i = 0; i < 12; i++)
        grid[i] = string(12, '.');

    grid[2][2] = '*';
    grid[2][9] = '*';

    grid[5][5] = '#';
    grid[5][6] = '#';
    grid[6][5] = '#';
    grid[6][6] = '#';

    grid[8][1] = '#';
    grid[8][2] = '#';
    grid[9][1] = '#';
    grid[9][2] = '*';

    grid[8][9] = '#';
    grid[8][10] = '#';
    grid[9][9] = '#';
    grid[9][10] = '#';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll L, r, c, i;

    cin >> L;

    while(L--)
    {
        init();

        cin >> r >> c;

        call(r-1, c-1, -1);

        cout << stk.size() << "\n";
        while(!stk.empty())
        {
            switch (stk.top())
            {
                case 0:
                    cout << "U";
                    break;
                case 1:
                    cout << "D";
                    break;
                case 2:
                    cout << "R";
                    break;
                default:
                    cout << "L";
            }
            stk.pop();
        }
        cout << "\n";
    }
}