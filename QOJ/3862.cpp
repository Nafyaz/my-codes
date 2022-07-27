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
pll boundary[MAXN];

void solve(int caseno)
{
    ll n, m, i;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
        cin >> p[i];
    for(i = 1; i <= n; i++)
        cin >> x[i];
    sort(x+1, x+n+1);
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