#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll arr[MAXN];

void solve(ll caseno)
{
    ll n, i, ans, leftCnt, rightCnt;
    ordered_set<pll> left, right;

    cin >> n;

    for(i = 0; i < n; i++)    
    {
        cin >> arr[i];
        right.insert({arr[i], i});
    }
    
    ans = 0;
    for(i = 0; i < n; i++)
    {
        right.erase({arr[i], i});

        // cout << i << "; left:\n";
        // for(auto u : right)
        //     cout << u.ff << " " << u.ss << "\n";
        // cout << "\n";

        // cout << i << "; right:\n";
        // for(auto u : right)
        //     cout << u.ff << " " << u.ss << "\n";
        // cout << "\n";

        leftCnt = i - left.order_of_key({arr[i]+1, -1});
        rightCnt = right.order_of_key({arr[i], -1});
        ans += leftCnt*rightCnt;

        left.insert({arr[i], i});
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