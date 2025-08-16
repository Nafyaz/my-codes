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
#define MAXN 200005

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pair<pLL, LL> a[MAXN];
LL ans[MAXN];

bool cmp(pair<pLL, LL> x, pair<pLL, LL> y)
{
    return x.ff.ss < y.ff.ss;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, l, r;
    ordered_set<LL> OS;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i].ff.ff >> a[i].ff.ss;
        a[i].ss = i;
    }

    sort(a, a+n, cmp);

    for(i = 0; i < n; i++)
    {
        ans[a[i].ss] = OS.size() - OS.order_of_key(a[i].ff.ff);
        OS.insert(a[i].ff.ff);
    }
    
    for(i = 0; i < n; i++)
        cout << ans[i] << "\n";
}