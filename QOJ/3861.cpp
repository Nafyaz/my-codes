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

ll t[MAXN], a[MAXN];
vector<pll> x;
vector<int> LIS;

void solve(ll caseno)
{
    ll n, v, i, pos;

    cin >> n >> v;

    for(i = 0; i < n; i++)
        cin >> t[i];
    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        if(abs(a[i]) > v*t[i])
            continue;

        x.push_back({v*t[i] - a[i], v*t[i] + a[i]});
    }
    // for(auto [p, q] : x)
    //     cout << p << " " << q << "\n";

    sort(x.begin(), x.end());


    for(auto [p, q] : x)
    {
        pos = upper_bound(LIS.begin(), LIS.end(), q) - LIS.begin();

        if(pos == LIS.size())
            LIS.push_back(q);
        else
            LIS[pos] = q;
    }

    cout << LIS.size() << "\n";
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