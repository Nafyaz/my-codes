#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll arr[MAXN], pref[MAXN];

void solve(ll caseno)
{
    ll n, k, i, ans;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }

    ordered_set<pll> OS;
    for(i = 1; i <= n; i++)
        OS.insert({pref[i] - i*k, i});

    // cout << "OS:\n";
    // for(auto u : OS)
    //     cout << u.first << " " << u.second << "\n";

    for(i = 0; i < n; i++)
    {
        ans += OS.size() - OS.order_of_key({pref[i] - i*k, -1});
        OS.erase({pref[i+1]-(i+1)*k, i+1});
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