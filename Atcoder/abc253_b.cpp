#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll h, w, i, j, cnt = 0;
    string s;
    ll dot[2][2];

    cin >> h >> w;

    for(i = 0; i < h; i++)
    {
        cin >> s;
        for(j = 0; j < w; j++)
        {
            if(s[j] == 'o')
            {
                dot[cnt][0] = i;
                dot[cnt][1] = j;
                cnt++;
            }
        }
    }

    cout << abs(dot[0][0] - dot[1][0]) + abs(dot[0][1] - dot[1][1]);
}