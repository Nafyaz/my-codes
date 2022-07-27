#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 300005

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pll arr[MAXN];
ordered_set<pll> allColor, thisColor[MAXN];

void solve(int caseno)
{
    ll n, i, ans, allSmall, thisSmall;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> arr[i].ss;
    for(i = 1; i <= n; i++)
        cin >> arr[i].ff;

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        allSmall = allColor.size() - allColor.order_of_key({arr[i].ff+1, -1});
        thisSmall = thisColor[arr[i].ss].size() - thisColor[arr[i].ss].order_of_key({arr[i].ff+1, -1});

        ans += allSmall - thisSmall;

        // show(allSmall);
        // show(thisSmall);
        // cout << "\n";

        allColor.insert({arr[i].ff, i});
        thisColor[arr[i].ss].insert({arr[i].ff, i});
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
