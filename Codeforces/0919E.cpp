#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cerr << #x << ": " << x << "; "
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

LL egcd(LL a, LL m, LL& x, LL& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    LL x1, y1;
    LL d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

//when gcd(a, mod) = 1
LL invmod(LL a, LL mod)
{
    LL x, y;
    egcd(a, mod, x, y);

    return (x%mod + mod) % mod;
}

LL getPow(LL a, LL p, LL limit)
{
    LL ret = 1;
    while(p)
    {
        if(a > limit)
            return -1;
            
        if(p&1)
            ret = (ret * a);
        
        if(ret > limit)
            return -1;

        a = (a*a);
        p /= 2;
    }

    return ret;
}

LL getMul(LL a, LL b, LL limit)
{
    if(a < 0 || b < 0)
        return -1;

    LL ret = 0;
    while(b)
    {
        if(a > limit)
            return -1;

        if(b&1)
            ret = (ret + a);

        if(ret > limit)
            return -1;
        
        a = (a + a);
        b /= 2;
    }

    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL a, b, p, x, ans;

    cin >> a >> b >> p >> x;

    if(a == 1)
    {
        cout << x/p + (b <= x%p) << "\n";
        return 0;
    }

    /*
    n = k1 (mod p-1)
    -------------------------------

    n*a^k1 = b (mod p)
    n = k2 = inv(a^k1, p) * b (mod p)
    -------------------------------

    n = k1 (mod p-1)
    n = k2 (mod p)
    -------------------------------

    inv1 = inv(p-1, p)
    inv2 = inv(p, p-1)

    n = (k1*inv2*(p-1) + k2*inv1*p)  (mod p*(p-1))
    -------------------------------
    */

    ans = 0;
    
    for(LL k1 = 0; k1 < p-1; k1++)
    {
        LL aK = bigmod(a, k1, p);
        LL inv_aK = invmod(aK, p);
        LL k2 = (inv_aK*b) % p;
        
        LL inv1 = invmod(p-1, p);
        LL inv2 = invmod(p, p-1);

        LL bigP = p*(p-1);

        LL n = (k1*inv2*p + k2*inv1*(p-1)) % bigP;

        // show(k1);
        // show(aK);
        // show(inv_aK);
        // show(k2);
        // show(inv1);
        // show(inv2);
        // show(bigP);
        // show(n) << "\n";

        ans += x/bigP + (n <= x%bigP);
    }

    cout << ans << "\n";
}