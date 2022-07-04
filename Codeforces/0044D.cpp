#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 5003

double x[MAXN], y[MAXN], z[MAXN];
double dist[MAXN];

double getDist(ll i, ll j)
{
    return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]));
}

void solve(ll caseno)
{
    ll n, i, j, p, q;
    double ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        if(i)
            dist[i] = getDist(0, i);
    }

    ans = (dist[1] + dist[2] + getDist(1, 2))/2;
    for(i = 1; i < n; i++)
    {
        for(j = 1; j < i; j++)        
            ans = min(ans, (dist[i] + dist[j] + getDist(i, j))/2);        
    }

    cout << fixed << setprecision(10) << ans << "\n";
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