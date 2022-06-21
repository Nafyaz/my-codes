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

void solve(ll caseno)
{
    ll n, m, i, j;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)        
        {
            cin >> arr[i][j];        
        }
    }
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