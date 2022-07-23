#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll h[MAXN];
ll prefCost[MAXN], sufCost[MAXN];

void solve(int caseno)
{
    ll n, i, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> h[i];

    ans = LLONG_MAX;

    prefCost[0] = 0;
    for(i = 2; i < n; i += 2)
    {
        prefCost[i] = prefCost[i-2] + max(0LL, max(h[i-1], h[i+1])+1 - h[i]);

//        show(i);
//        show(prefCost[i]);
//        show(h[i-1]);
//        show(h[i]);
//        show(h[i+1]);
//        cout << max(0LL, max(h[i-1], h[i+1])+1 - h[i]) << ";";
//        cout << "\n";
    }
    ans = min(ans, prefCost[(n-1)/2*2]);

    if(n&1)
    {
        cout << ans << "\n";
        return;
    }

    sufCost[n+1] = 0;
    for(i = n-1; i >= 3; i -= 2)
        sufCost[i] = sufCost[i+2] + max(0LL, max(h[i-1], h[i+1])+1 - h[i]);

    for(i = 0; i < n; i += 2)
        ans = min(ans, prefCost[i] + sufCost[i+3]);

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

