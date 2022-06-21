#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll n, i, m;

    cin >> n;

    vector<ll> ans;
    m = 1;
    for(i = 1; i < n; i++)
    {
        if(__gcd(i, n) == 1)
        {
            ans.push_back(i);
            m = (m * i)%n;
        }
    }

    if(m != 1)
        ans.erase(find(ans.begin(), ans.end(), m));

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u << " ";
    cout << "\n";
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