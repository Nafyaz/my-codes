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
#define MAXN 500005

LL a[MAXN], b[MAXN];

LL mulmod(LL a, LL b, LL mod = MOD)
{
    LL ret = 0;

    while(b)
    {
        if(b&1)
            ret = (ret + a) % mod;
        
        a =(a + a) % mod;
        b /= 2;
    }

    return ret;
}

LL bigmod(LL a, LL p, LL mod = MOD)
{
    LL ret = 1%mod;
    while(p)
    {
        if(p&1)
            ret = mulmod(ret, a, mod);
        a = mulmod(a, a, mod);
        p /= 2;
    }
    return ret;
}

bool isPrime(LL n) 
{
    if (n < 2 or n % 6 % 4 != 1) 
        return (n | 1) == 3;

    LL bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    LL s = __builtin_ctzll(n - 1), d = (n - 1) >> s;

    for (LL b : bases) 
    {
        if(b%n == 0)
            continue;

        LL p = bigmod(b % n, d, n);

        if(p == 1)
            continue;

        LL iter = s;

        while (p != n-1 and iter--)
            p = mulmod(p, p, n);
        
        if (p != n-1)
            return false;
    }
    return true;
}

LL get_factor(LL n) 
{
    auto f = [&](LL x) { return mulmod(x, x, n) + 1; };
    LL slow = 0, fast = 0, st = 2, div;
    while(true)
    {
        if(slow == fast)
        {
            slow = st++;
            fast = f(slow);
        }

        div = gcd(abs(fast - slow), n);

        if(div != 1 && div != n)
            return div;

        slow = f(slow); 
        fast = f(f(fast));
    }
}

map<LL, LL> factorize(LL n) 
{
    map<LL, LL> res;
    if (n < 2) return res;
    LL small_primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (LL p : small_primes)
        for (; n % p == 0; n /= p, res[p]++);

    auto _factor = [&](LL n, auto &_factor) 
    {
        if (n == 1)
            return;
        if (isPrime(n))
            res[n]++;
        else
        {
            LL x = get_factor(n);
            _factor(x, _factor);
            _factor(n / x, _factor);
        }
    };
    _factor(n, _factor);
    return res;
}

void solve(int caseno)
{
    LL n, i, j, gcdA;
    map<LL, LL> factA, factB, factGcdA;
    bool canAlice, canBob;

    cin >> n;

    gcdA = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        map<LL, LL> temp = factorize(a[i]);

        if(factA.size() < temp.size())
            swap(factA, temp);

        for(auto &[p, cnt] : temp)
            factA[p] += cnt;

        gcdA = gcd(gcdA, a[i]);
    }

    factGcdA = factorize(gcdA);

    for(i = 0; i < n; i++)
    {
        cin >> b[i];

        map<LL, LL> temp = factorize(b[i]);

        if(factB.size() < temp.size())
            swap(factB, temp);

        for(auto &[p, cnt] : temp)
            factB[p] += cnt;
    }

    cout << "Case " << caseno << ": ";

    canAlice = true;
    for(auto &[p, cnt] : factB)
    {
        if(factA.find(p) == factA.end())
        {
            canAlice = false;
            break;
        }
    }

    if(canAlice == false)
    {
        cout << "No No\n";
        return;
    }

    canBob = true;
    for(i = 0; i < n; i++)
    {
        a[i] /= gcdA;
        
        for(auto &[p, cnt] : factGcdA)
        {
            while(b[i] % p == 0)
                b[i] /= p;
        }

        if(a[i] != b[i])
        {
            canBob = false;
            break;
        }
    }

    cout << "Yes " << (canBob? "Yes\n" : "No\n");
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