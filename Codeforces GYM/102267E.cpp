#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> R[4];
string grid[15];

void print()
{
    ll i, j, k;
    bool isRobot;

    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
        {
            isRobot = 0;
            for(k = 0; k < 4; k++)
            {
                if(R[k] == make_pair(i, j))
                {
                    isRobot = 1;
                    cout << setw(2) << "R" << k+1;

                    break;
                }
            }

            if(!isRobot)
                cout << setw(3) << grid[i][j];
        }

        cout << "\n";
    }

    cout << "\n\n";
}

bool canMove(ll row, ll col)
{
    if(row < 0 || row >= 12 || col < 0 || col >= 12 || grid[row][col] == '#')
        return 0;
    
    for(ll i = 0; i < 4; i++)
    {
        if(R[i] == make_pair(row, col))
            return 0;
    }

    return 1;
}

void move(ll dRow, ll dCol)
{
    bool moved[4] = {0};
    ll i, j;


    for(i = 0; i < 16; i++)
    {
        for(j = 0; j < 4; j++)
        {            
            if(moved[j])
                continue;
            
            ll newRow = R[j].ff + dRow;
            ll newCol = R[j].ss + dCol;
            if(canMove(newRow, newCol))
            {
                R[j].ff = newRow;
                R[j].ss = newCol;
                moved[j] = 1;
            }
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll L, i;
    string s;

    for(i = 0; i < 12; i++)
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
    grid[9][9] = '*';
    grid[9][10] = '#';

    cin >> L;

    s = "";
    for(i = 0; i < 20; i++)
        s = s +"LD";
    s = s + "UULLLDDLLUULLDDLLUULLDDLL" + "RRRRRRRRDDUUURDDDUUUUULLDDDDRRUUUU";

    while(L--)
    {
        for(i = 0; i < 4; i++)        
        {
            cin >> R[i].ff >> R[i].ss;
            R[i].ff--;
            R[i].ss--;
        }        

        // for(auto u : s)
        // {
        //     if(u == 'U')
        //     move(-1, 0);
        //     else if(u == 'D')
        //         move(1, 0);
        //     else if(u == 'R')
        //         move(0, 1);
        //     else
        //         move(0, -1);

        //     print();
        //     this_thread::sleep_for (std::chrono::milliseconds(250));
        // }

        cout << s.size() << "\n" << s << "\n";
    }

}