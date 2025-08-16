#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 1003

ll p[maxN], pos[maxN];

void solve(ll caseno)
{
    ll n, i, j;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<pll> ans;
    for(i = 1; i <= n; i++)
    {
        for(j = n; j > 1; j--)
        {
            if(pos[j] < pos[j-1])
            {
                swap(pos[j], pos[j-1]);      
                swap(p[pos[j]], p[pos[j-1]]);          
                ans.push_back({min(pos[j], pos[j-1]), max(pos[j], pos[j-1])});
            }
        }
    }

    // for(i = 1; i <= n; i++)
    //     cout << p[i] << " ";
    // cout << "\n";

    // cout << (n*n < ans.size()) << "\n";
    // cout << is_sorted(p+1, p+n+1) << "\n";

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
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