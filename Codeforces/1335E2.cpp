#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN];
vector<ll> pos[202];

void solve(ll caseno)
{
    ll n, i, j, ans, bg, ed, cnt;

    for(i = 1; i <= 200; i++)
        pos[i].clear();

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    
    ans = 0;
    for(i = 1; i <= 200; i++)
    {
        ans = max(ans, (ll)pos[i].size());
        for(bg = 0, ed = (ll)pos[i].size() - 1; bg < ed; bg++, ed--)
        {
            for(j = 1; j <= 200; j++)
            {
                cnt = lower_bound(pos[j].begin(), pos[j].end(), pos[i][ed]) - upper_bound(pos[j].begin(), pos[j].end(), pos[i][bg]);
                ans = max(ans, 2*(bg+1) + cnt);
            }
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