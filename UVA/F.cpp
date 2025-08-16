#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

long long bigmod(long long a, long long p, long long mod)
{
    if (p == 0)
        return 1%mod;
    if (p == 1)
        return a%mod;

    long long ret = bigmod(a, p/2, mod);
    ret = (ret*ret) % mod;
    if (p&1)
        return (a*ret)%mod;

    return ret;
}

long long invmod(long long a, long long mod)
{
    return bigmod(a, mod-2, mod);
}

void solve(int caseno)
{
    long long n;

    cin >> n;


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