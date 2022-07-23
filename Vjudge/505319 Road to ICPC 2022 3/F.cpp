#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll a[MAXN];
ll pMax[MAXN], rMax;

void solve(int caseno)
{
    ll n, p, q, r, i, ans;

    cin >> n >> p >> q >> r;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];

        if(i == 1)
            pMax[i] = p*a[i];
        else
            pMax[i] = max(pMax[i-1], p*a[i]);
    }

    ans = LLONG_MIN;
    for(i = n; i >= 1; i--)
    {
        if(i == n)
            rMax = r*a[i];
        else
            rMax = max(rMax, r*a[i]);

        ans = max(ans, pMax[i] + q*a[i] + rMax);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
