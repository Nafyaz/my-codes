#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll parent[MAXN];
ll L[MAXN], R[MAXN], a[MAXN];

void solve(ll caseno)
{
    ll n, i, j, ans, mnA;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        parent[i] = -1;
        a[i] = 0;
    }

    for(i = 2; i <= n; i++)
        cin >> parent[i];

    for(i = 1; i <= n; i++)    
        cin >> L[i] >> R[i];

    ans = 0;
    for(i = n; i >= 1; i--)
    {   
        if(L[i] <= a[i] && a[i] <= R[i])
            continue;

        ans++;
        mnA = INT_MAX;
        for(j = i; j != -1 && mnA > 0; j = parent[j])
        {
            mnA = min(mnA, R[j] - a[j]);
            a[j] += mnA;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}