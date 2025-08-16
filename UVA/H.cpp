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

long long dp[102][2][51][51][51][51];
long long P, Q, B1, B2, S1, S2;

long long func(long long rem, long long idx, long long s1, long long s2, long long o1, long long o2)
{
    if (rem == 0)
        return dp[rem][idx][s1][s2][o1][o2] = 1;

    
}

void solve(int caseno)
{
    long long n;

    cin >> P >> Q >> n;
    cin >> B1 >> B2;
    cin >> S1 >> S2;

    cout << func(n, 0, P, Q, )
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