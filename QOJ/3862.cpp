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

ll p[MAXN], x[MAXN];
ll pref[MAXN];

void solve(int caseno)
{
    ll n, m, i, j, ans, l, r, pos, dist;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> p[i];
        pref[i] = pref[i-1] + p[i];
    }
    for(i = 1; i <= m; i++)
    {
        cin >> x[i];
    }

    sort(x+1, x+m+1);

    if(x[1] > 0)
        ans = pref[min(n, (x[1]-1)/100 + 1)];
    else
        ans = 0;
    
    for(i = 1; i < m; i++)
    {
        dist = x[i+1] - x[i];

        l = x[i]/100 + 2;
        r = (x[i+1] - 1)/100 + 1;

        for(j = l; j <= r && j <= n; j++)
        {
            if(dist&1)
                pos = min({n, r, (100*(j-1) + dist/2)/100 + 1});
            else
                pos = min({n, r, (100*(j-1) + dist/2 -1)/100 + 1});
                
            ans = max(ans, pref[pos] - pref[j-1]);
        }
    }

    if(100*(n-1) > x[m])
        ans = max(ans, pref[n] - pref[x[m]/100+1]);

    cout << ans << "\n";
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

/*
2 2
10 20
0 100
*/