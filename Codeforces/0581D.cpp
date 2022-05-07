#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x[3], y[3];
ll sq;
string grid[200];

void paint(ll stx, ll sty, ll h, ll w, ll c)
{
    ll i, j;
    for(i = stx; i < stx+h; i++)
    {
        for(j = sty; j < sty+w; j++)
            grid[i][j] = c;
    }
}

void remove(ll stx, ll sty, ll h, ll w)
{
    ll i, j;
    for(i = stx; i < stx+h; i++)
    {
        for(j = sty; j < sty+w; j++)
        {
            grid[i][j] = '.';
        }
    }
}

bool check()
{
    ll i, j;
    for(i = 0; i < sq; i++)
    {
        for(j = 0; j < sq; j++)
        {
            if(grid[i][j] == '.')
                return 0;
        }
    }

    return 1;
}

bool call(ll pos, ll mask)
{
    // cout << "pos: " << pos << "; mask: " << mask << "\n";
    if(pos == 3)
        return check();

    ll i, stx, sty;
    bool empty;

    for(i = 0; i < 3; i++)
    {
        if((mask & (1 << i)) == 0)
        {     
            empty = 0;        
            for(stx = 0; stx < sq && !empty; stx++)
            {
                for(sty = 0; sty < sq && !empty; sty++)
                {
                    // cout << "stx: " << stx << "; sty: " << sty << "; grid[stx][sty] = " << grid[stx][sty] << "\n";
                    if(grid[stx][sty] == '.')
                        empty = 1;
                }
            }

            stx--;
            sty--;

            if(stx + x[i] <= sq && sty + y[i] <= sq)
            {
                paint(stx, sty, x[i], y[i], 'A'+i);
                if(call(pos+1, mask | (1 << i)))
                    return 1;
                remove(stx, sty, x[i], y[i]);
            }

            if(stx + y[i] <= sq && sty + x[i] <= sq)
            {
                paint(stx, sty, y[i], x[i], 'A'+i);
                if(call(pos+1, mask | (1 << i)))
                    return 1;
                remove(stx, sty, y[i], x[i]);
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j, sum = 0;

    for(i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
        sum += x[i]*y[i];
    }

    sq = sqrt(sum);

    if(sq*sq != sum)
    {
        cout << -1;
        return 0;
    }

    for(i = 0; i < sq; i++)
        grid[i] = string(sq, '.');

    // for(i = 0; i < sq; i++)
    // {
    //     for(j = 0; j < sq; j++)
    //         cout << grid[i][j];
    //     cout << "\n";
    // }
    
    if(call(0, 0))
    {
        cout << sq << "\n";
        for(i = 0; i < sq; i++)
        {
            for(j = 0; j < sq; j++)
                cout << grid[i][j];
            cout << "\n";
        }
    }
    else
        cout << "-1";
}