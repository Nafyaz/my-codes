#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[1003][1003];
ll mn[1003][1003], mx[1003][1003];

void solve(ll caseno)
{
    ll n, m, i, j;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    if((n+m-1)%2 == 1)
    {
        cout << "NO\n";
        return;
    }

    mn[0][0] = mx[0][0] = arr[0][0];
    for(j = 1; j < m; j++)
        mn[0][j] = mx[0][j] = mn[0][j-1] + arr[0][j];

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(j == 0)            
                mn[i][j] = mx[i][j] = mn[i-1][j] + arr[i][j];
            else
            {
                mn[i][j] = min(mn[i][j-1], mn[i-1][j]) + arr[i][j];
                mx[i][j] = max(mx[i][j-1], mx[i-1][j]) + arr[i][j];
            }
        }
    }

    cout << (mx[n-1][m-1] >= 0 && mn[n-1][m-1] <= 0? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}