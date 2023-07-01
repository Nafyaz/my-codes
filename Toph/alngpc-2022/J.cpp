#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
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

ordered_set<int> OS;

int cnt(int low, int high)
{
    int v1 = OS.order_of_key(low);
    int v2 = OS.order_of_key(high + 1);

    return v2 - v1;
}

void solve(int caseno)
{
    int n, q, type, x, low, high, mid, ans;
    OS.clear();

    cin >> n >> q;

    cout << "Case " << caseno << ":\n";
    while(q--)
    {
        cin >> type >> x;

        if(type == 1)        
            OS.insert(x);
        else
        {
            low = x;
            high = n+1;
            while(low <= high)
            {
                if(low == high)
                {
                    ans = low;
                    break;
                }

                mid = (low + high) / 2;

                if(cnt(low, mid) == mid - low +1)
                    low = mid + 1;
                else
                    high = mid;
            }

            cout << ans << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}