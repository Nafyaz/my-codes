#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1500006

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll arr[MAXN];
ll freq[MAXN];
ordered_set<ll> OS;

ll getMEX(ll mx)
{
    if((*(OS.find_by_order(0))) != 0)
        return 0;

    ll low, high, mid, ret;

    low = 0;
    high = mx;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(OS.order_of_key(mid+1) < mid+1)
        {
            ret = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ret;
}

void solve(ll caseno)
{
    ll n, m, i, ans;

    cin >> n >> m;

    ans = INT_MAX;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        
        freq[arr[i]]++;
        OS.insert(arr[i]);

        if(i >= m-1)
        {
            ans = min(ans, getMEX(m));

            freq[arr[i-m+1]]--;
            if(freq[arr[i-m+1]] == 0)        
                OS.erase(arr[i-m+1]);        
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