#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, i, a, len, ans, change;
    LL l, r;
    ordered_set<LL> OS;

    cin >> n;

    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        ans += OS.order_of_key(a);

        OS.insert(a);
    }

    ans = n*(n-1)/2 - ans;
    ans %= 2;

    cin >> m;
    while(m--)
    {
        cin >> l >> r;

        len = r-l+1;

        change = len*(len-1)/2;
        change %= 2;

        ans = (ans + change) % 2;

        cout << (ans? "odd\n" : "even\n");
    }
}