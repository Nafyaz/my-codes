#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n;
ll grid[502][502];

void solve()
{
    ll i, j;

    cin >> m >> n;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cin >> grid[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}