#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    vector<ll> w[2];
    ll n, i, j, t, temp, total, ans;

    cin >> n;

    w[0].push_back(0);
    w[1].push_back(0);
    for(i = 0; i < n; i++)
    {
        cin >> t >> temp;
        w[t-1].push_back(temp);
    }

    sort(w[0].begin(), w[0].end());
    sort(w[1].begin(), w[1].end());


    for(i = 1; i < w[0].size(); i++)
        w[0][i] += w[0][i-1];
    for(i = 1; i < w[1].size(); i++)
        w[1][i] += w[1][i-1];


    total = w[0].size() - 1 + 2*(w[1].size() - 1);
    ans = INT_MAX;
    for(i = 0; i < w[0].size(); i++)
    {
        for(j = 0; j < w[1].size(); j++)
        {
            if(total - (i + 2*j) >= w[0][i] + w[1][j])
                ans = min(ans, total - (i + 2*j));
        }
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