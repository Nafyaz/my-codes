#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN];
ll Log[MAXN], sparse[MAXN][22];

ll getMax(ll bg, ll ed)
{
    ll d = Log[ed - bg + 1];

    return max(sparse[bg][d], sparse[ed - (1LL << d) + 1][d]);
}

void solve(int caseno)
{
    ll n, m, i, j, q, xS, yS, xF, yF, k;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> arr[i];
        sparse[i][0] = arr[i];
    }

    for(j = 1; j < 22; j++)
    {
        for(i = 1; i+(1<<j) - 1 <= m; i++)
            sparse[i][j] = max(sparse[i][j-1], sparse[i + (1LL << (j-1))][j-1]);
    }

    cin >> q;
    while(q--)
    {
        cin >> xS >> yS >> xF >> yF >> k;

        if(yS > yF)
        {
            swap(xS, xF);
            swap(yS, yF);
        }

        xS = xS + (n - xS)/k*k;
        xF = xF + (n - xF)/k*k;

        // show(xS);
        // show(xF);
        // cout << "\n";

        if(xS != xF || (yF - yS)%k != 0 || getMax(yS, yF) >= xS)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    Log[1] = 0;
    for(ll i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
