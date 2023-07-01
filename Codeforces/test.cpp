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

LL bigmod(LL a, LL p, LL mod)
{
    LL ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret * a) % mod;
        
        a = (a*a) % mod;
        p /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL a, b, p, x;

    cin >> a >> b >> p >> x;

    for(LL n = 1; n <= x; n++)
    {
        LL k = (n*bigmod(a, n, p))%p;

        // show(n);
        // show(k) << "\n";

        if(k == b)
            show(n);
    }
}