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
map<ll, ll> mp;

void solve(int caseno)
{
    ll n, m, i, j, pos, ans, sum, dist;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> p[i];
    for(i = 0; i < m; i++)
        cin >> x[i];

    sort(x, x+m);

    for(i = 0; i < n; i++)
    {
        pos = 100*i;
        j = lower_bound(x, x+m, pos) - x;
        dist = LLONG_MAX;

        if(j < m)
            dist = min(dist, x[j] - pos);
        
        j--;

        if(j >= 0)
            dist = min(dist, pos - x[j]);

        if(dist == 0)
            continue;

        pos *= 2;
        dist *= 2;

        mp[pos-dist+1] += p[i];
        mp[pos+dist] -= p[i];
    }

    ans = sum = 0;
    for(auto p : mp)
    {
        sum += p.ss;
        ans = max(sum, ans);
    }

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