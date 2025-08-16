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

ll arr[MAXN];
ordered_set<pll> OS;

void solve(ll caseno)
{
    ll n, q, i, k, x, a, b;
    string type;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        OS.insert({arr[i], i});
    }

    while(q--)
    {
        cin >> type;
        if(type == "!")
        {
            cin >> k >> x;
            OS.erase(*OS.find_by_order(OS.order_of_key({arr[k], k})));
            arr[k] = x;
            OS.insert({arr[k], k});
        }
        else
        {
            cin >> a >> b;
            cout << OS.order_of_key({b+1, -1}) - OS.order_of_key({a, -1}) << "\n";
        }

        // cout << q << ":\n";
        // for(auto u : OS)
        //     cout << u.ff << " " << u.ss << "; ";
        // cout << "\n";
    }
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