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

map<LL, LL> dp;

LL call(LL x)
{
    // show(x) << "\n";
    if(x == 0)
        return 0;

    if((x&(x-1)) == 0)
        return 1;

    if(x%2 == 0)
        return call(x/2);

    if(dp.find(x) != dp.end())
        return dp[x];

    return dp[x] = min(1 + call(x/2), 1 + call((x+1)/2));
}

void solve(int caseno)
{
    LL x, bit;

    cin >> x;

    x = abs(x);

    cout << call(x) << "\n";
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