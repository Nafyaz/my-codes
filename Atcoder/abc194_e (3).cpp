#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1500006

vector<ll> pos[MAXN];

void solve(ll caseno)
{
    ll n, m, i, j, a;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        pos[a].push_back(i);
    }

    for(i = 0; i <= n; i++)
    {
        if(pos[i].empty() || pos[i][0] >= m)
        {
            cout << i << "\n";
            return;
        }

        for(j = 1; j < pos[i].size(); j++)
        {
            if(pos[i][j] - pos[i][j-1] >= m+1)
            {
                cout << i << "\n";
                return;
            }
        }

        if(n-1 - pos[i].back() >= m)
        {
            cout << i << "\n";
            return;
        }
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