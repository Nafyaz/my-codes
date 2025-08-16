#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll W[MAXN];
vector<ll> w[2];

void solve(ll caseno)
{
    ll n, i, temp, ans, child, adult;
    string s;

    cin >> n >> s;

    for(i = 0; i < n; i++)
    {
        cin >> W[i];

        if(s[i] == '0')
            w[0].push_back(W[i]);
        else
            w[1].push_back(W[i]);
    }

    sort(W, W+n);
    sort(w[0].begin(), w[0].end());
    sort(w[1].begin(), w[1].end());

    ans = 0;
    for(i = 0; i < n; i++)
    {
        child = lower_bound(w[0].begin(), w[0].end(), W[i]) - w[0].begin();
        adult = w[1].size() - (lower_bound(w[1].begin(), w[1].end(), W[i]) - w[1].begin());
        ans = max(ans, child + adult);

        child = upper_bound(w[0].begin(), w[0].end(), W[i]) - w[0].begin();
        adult = w[1].size() - (upper_bound(w[1].begin(), w[1].end(), W[i]) - w[1].begin());
        ans = max(ans, child + adult);
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