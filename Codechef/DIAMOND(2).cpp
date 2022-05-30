#include<bits/stdc++.h>
using namespace std;
#define ll long long

double C[2003][2003];

void solve()
{
    ll n, i;
    double v, ans = 0;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> v;

        ans += v*C[n][i];
    }

    cout << fixed << setprecision(6) << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j;

    C[1][1] = 1;
    for(i = 2; i < 2003; i++)
    {
        C[i][1] = 0.5;
        for(j = 2; j <= i; j++)        
            C[i][j] += 0.5 - 0.5*C[i-1][j-1];
        
        for(j = 1; j < i; j++)
            C[i][j] += 0.5 - 0.5*C[i-1][j];
        C[i][i] += 0.5;
    }

    // for(i = 1; i <= 3; i++)
    // {
    //     for(j = 1; j <= 3; j++)
    //         cout << C[i][j] << " ";
    //     cout << endl;
    // }
    
    cin >> T;

    while(T--)
    {
        solve();
    }
}