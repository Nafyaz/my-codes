#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

vector<int> adjLST[MAXN];
int adjMTT[3003][3003];

void solve(int caseno)
{
    int s, t, m, i, u, v, cur;

    cin >> s >> t >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> u >> v;

        adjLST[u].push_back(v);
    }

    for(cur = 1; cur <= s; cur++)
    {
        for(auto nxt1 : adjLST[cur])
        {
            for(auto nxt2 : adjLST[cur])
            {
                if(nxt1 < nxt2)
                {
                    if(adjMTT[nxt1-s][nxt2-s] == 0)
                    {
                        adjMTT[nxt1-s][nxt2-s] = cur;
                        adjMTT[nxt2-s][nxt1-s] = cur;
                    }
                    else
                    {
                        cout << nxt1 << " " << adjMTT[nxt1-s][nxt2-s] << " " << nxt2 << " " << cur << "\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}