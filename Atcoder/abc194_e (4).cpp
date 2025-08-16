#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1500006

ll last[MAXN];

void solve(ll caseno)
{
    ll n, m, i, x, ans;

    cin >> n >> m;

    ans = INT_MAX;
    for(i = 1; i <= n; i++)
    {
        cin >> x;

        if(i - last[x] > m)
            ans = min(ans, x);

        last[x] = i;
    }

    for(i = 0; i <= n; i++)
    {
        if(n - last[i] >= m)
            ans = min(ans, i);
    }

    cout << ans << "\n";
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

/*
5 5
0 1 2 3 4
*/