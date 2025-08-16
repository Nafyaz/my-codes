#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 100000007
#define MAXN 5000006

bool isPrime[MAXN];
vector<LL> primes;
void sieve()
{
    LL i, j;

    isPrime[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        isPrime[i] = 1;

    for(i = 3; i < MAXN; i += 2)
    {
        if(isPrime[i])
        {
            for(j = i*i; j < MAXN; j += 2*i)
                isPrime[j] = 0;
        }
    }

    primes.push_back(2);
    for(i = 3; i < MAXN; i += 2)
    {
        if(isPrime[i])
            primes.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    LL n, ans;

    while(1)
    {
        cin >> n;
        if(!n)
            break;
        
        ans = 1;
        for(LL i = 0; i < primes.size(); i++)
        {
            LL p = primes[i];
            LL tempN = n;
            LL tempP = p;
            LL add1, add2, total = 0;

            while(tempN)
            {
                LL cnt = tempN / p;

                add1 = (cnt * (n%tempP + 1)) % MOD;
                add2 = ((cnt-1)*cnt/2) % MOD;
                add2 = (add2 * tempP) % MOD;

                total = (total + add1 + add2) % MOD;

                tempN /= p;
                tempP *= p;
            }

            ans = (ans * (total + 1)) % MOD;
        }

        cout << ans << "\n";
    }
}