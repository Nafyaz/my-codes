#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

long long a[MAXN];
map<long long, long long> freq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k, i, pref, ans;

    cin >> n >> k;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    freq[0] = 1;
    pref = 0;
    ans = 0;
    for (i = 1; i <= n; i++)
    {
        pref += a[i];
        if (freq.find(pref - k) != freq.end())
        {
            ans += freq[pref - k];
        }

        freq[pref] ++;
    }

    cout << ans << "\n";
}