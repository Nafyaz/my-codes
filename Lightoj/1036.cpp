#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n;
ll Uranium[502][502], Radium[502][502];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j;

    cin >> T;

    while(T--)
    {
        cin >> m >> n;

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                cin >> Uranium[i][j];
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                cin >> Radium[i][j];
        }
    }
}