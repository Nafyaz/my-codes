#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m;
ll arr[MAXN];
map<ll, ll> freq;
ordered_set<ll> OS;

bool isPossible(ll mex)
{
    ll i;
    freq.clear();
    OS.clear();
    
    for(i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        OS.insert(arr[i]);

        if(i >= m-1)
        {
            if(OS.order_of_key(mex+1) < mex+1)
                return 1;

            freq[arr[i-m+1]]--;
            if(freq[arr[i-m+1]] == 0)        
                OS.erase(arr[i-m+1]);        
        }
    }

    return 0;
}

void solve(ll caseno)
{
    ll i, ans, low, high, mid;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    low = 0;
    high = n;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(isPossible(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
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