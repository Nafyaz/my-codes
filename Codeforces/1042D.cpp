#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll arr[maxN], pref[maxN];

void solve(ll caseno)
{
    ll i, n, t, ans, cnt;

    ordered_set<pll> OS;

    cin >> n >> t;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }

    ans = 0;
    OS.insert({0, 0});

    for(i = 1; i <= n; i++)
    {
        cnt = OS.order_of_key({pref[i] - t + 1, -1});
        OS.insert({pref[i], i});
        ans += i - cnt;
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