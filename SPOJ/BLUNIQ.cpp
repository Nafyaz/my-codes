#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

void solve(ll caseno)
{
    ll n, low, high, mid, x, finalX;
    ll type;

    ordered_set<ll> OS;

    cin >> n;

    while(n--)
    {
        cin >> type;
        
        if(type == 1)
        {
            cin >> x;

            low = x;
            high = INT_MAX;
            
            while(low <= high)
            {
                mid = (low + high) / 2;
                // cout << mid << "\n";
                if((ll)(OS.order_of_key(mid+1) - OS.order_of_key(x)) < mid - x + 1)
                {
                    finalX = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }

            OS.insert(finalX);
            cout << finalX << "\n";
        }
        else
        {
            cin >> x;
            OS.erase(x);
        }
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