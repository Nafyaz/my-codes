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

void solve(int caseno)
{
    ll n, i, x, a, prev, ans;
    map<ll, ll> freq;

    cin >> n >> x;

    freq[0] = 1;
    ans = prev = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a;
        prev += a;

        ans += freq[prev - x];

        freq[prev]++;
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