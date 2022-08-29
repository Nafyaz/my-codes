#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long LL;
typedef pair<LL, LL> pLL;
#define MAXN 1000006

LL leastFactor[MAXN];
vector<LL> primes;

void linSieve()
{
    LL i, j;
    for (i = 2; i < MAXN; ++i)
    {
        if (leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);
        }
        for (j = 0; j < (LL)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < MAXN; ++j)
        {
            leastFactor[i * primes[j]] = primes[j];
        }
    }
}

LL bigmod(LL a, LL p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a;

    LL res = bigmod(a, p/2);
    res = (res*res);
    if(p&1)
        return (a*res);
    return res;
}

LL getTotient(LL bU, LL bV)
{
    unordered_map<LL, LL> mp;

    while(bU > 1)
    {
        mp[leastFactor[bU]]++;
        bU /= leastFactor[bU];
    }

    while(bV > 1)
    {
        mp[leastFactor[bV]]++;
        bV /= leastFactor[bV];
    }

    LL ret = 1;

    for(auto u : mp)
        ret = ret*(bigmod(u.ff, u.ss) - bigmod(u.ff, u.ss-1));

    return ret;
}

int main()
{
    linSieve();

    cout << getTotient(3797, 5232);
}
