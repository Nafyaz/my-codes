#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll dist[502][502];

void solve(ll caseno)
{
    ll n, m, q, i, j, k, a, b, c;

    cin >> n >> m >> q;

    memset(dist, -1, sizeof dist);
    for(i = 1; i <= n; i++)
        dist[i][i] = 0;

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;

        if(dist[a][b] == -1)        
            dist[a][b] = dist[b][a] = c;
        else
            dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }


    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(dist[i][k] != -1 && dist[k][j] != -1)
                {
                    if(dist[i][j] == -1)
                        dist[i][j] = dist[i][k] + dist[k][j];
                    else
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while(q--)
    {
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}