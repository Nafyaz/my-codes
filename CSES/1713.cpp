#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll ans[MAXN];

void solve(ll caseno)
{
    ll n;

    cin >> n;
    cout << ans[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0, i, j;

    for(i = 1; i < MAXN; i++)
    {
        for(j = i; j < MAXN; j += i)
            ans[j]++;
    }

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}