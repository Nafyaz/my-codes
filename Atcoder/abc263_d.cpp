#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 200005

ll a[MAXN];
ll pref[MAXN], suff[MAXN];
ll prefMin[MAXN], suffMin[MAXN];

void solve(int caseno)
{
    ll n, l, r, i, total, ans;

    cin >> n >> l >> r;

    total = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    for(i = 1; i <= n; i++)
    {
        pref[i] = pref[i-1] + a[i];
        prefMin[i] = min(prefMin[i-1], l*i - pref[i]);
    }

    for(i = n; i >= 1; i--)
    {
        suff[i] = suff[i+1] + a[i];
        suffMin[i] = min(suffMin[i+1], r*(n-i+1) - suff[i]);
    }

    ans = total;
    for(i = 1; i <= n+1; i++)
        ans = min(ans, prefMin[i-1] + total + suffMin[i]);

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

