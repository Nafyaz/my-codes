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

void solve(int caseno)
{
    ll n, x, a, i, l, r, ans;

    cin >> n >> x;

    l = INT_MIN;
    r = INT_MAX;
    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(a-x > r || a+x < l)
        {
            ans++;
            l = a-x;
            r = a+x;
        }

        l = max(l, a-x);
        r = min(r, a+x);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

