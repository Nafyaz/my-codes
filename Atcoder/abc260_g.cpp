#include<bits/stdc++.h>
using namespace std;

string s[2004];
int temp[2004][10012];
int op1[2004][10012], op2[2004][10012];
int ans[2004][10012];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q, i, j, k;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = '*' + s[i];
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(s[i][j] == 'O')
            {
                temp[i][j]++;

                if(i+m <= n)
                    temp[i+m][j]--;
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            op1[i][j] = op1[i-1][j] + temp[i][j];
    }

    memset(temp, 0, sizeof temp);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(s[i][j] == 'O')
            {
                if(i+m <= n)
                    temp[i+m][j]++;

                temp[i][j+2*m]--;
            }
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= 4*n; j++)
            op2[i][j] = op2[i-1][j+2] + temp[i][j];
    }


    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= 4*n; j++)
            ans[i][j] = ans[i][j-1] + op1[i][j] + op2[i][j];
    }

//    for(i = 0; i <= n; i++)
//    {
//        for(j = 0; j <= n; j++)
//            cout << setw(3) << op1[i][j] + op2[i][j];
//        cout << "\n";
//    }

    cin >> q;
    while(q--)
    {
        cin >> i >> j;
        cout << ans[i][j] << "\n";
    }
}
/*
5 3
XXXXX
XXXXX
XXXXX
OXXXX
XXXXX
0
*/
