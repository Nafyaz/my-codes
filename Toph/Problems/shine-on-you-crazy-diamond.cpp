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
#define MAXN 1000006

vector<int> primes;
bool isPrime[MAXN];
int freq[MAXN];
vector<pii> v;

void sieve()
{
    LL i, j;

    isPrime[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        isPrime[i] = 1;

    for(i = 3; i < MAXN; i += 2)
    {
        if(!isPrime[i])
            continue;
        for(j = i*i; j < MAXN; j += 2*i)
            isPrime[j] = 0;
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
    int n, a, ans, p1, p2, sum;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a;

        for(int j = 1; j*j <= a; j++)
        {
            if(a%j == 0)
            {
                freq[j]++;

                if(j*j != a)
                    freq[a/j]++;
            }
        }
    }

    for(int i = 0; i < primes.size(); i++)
        v.push_back({freq[primes[i]], primes[i]});

    sort(v.begin(), v.end(), greater<pii>());

    ans = 0;
    p1 = 2;
    p2 = 3;
    for(int i = 0; i < primes.size(); i++)
    {
        for(int j = i+1; j < primes.size(); j++)
        {
            sum = v[i].ff + v[j].ff;

            if(sum <= ans)
                break;
            
            if((LL)v[i].ss*v[j].ss < MAXN)
                sum -= freq[v[i].ss*v[j].ss];

            if(sum > ans)
            {
                ans = sum;
                p1 = v[i].ss;
                p2 = v[j].ss;
            }
        }
    }

    cout << n-ans << "\n" << p1 << " " << p2 << "\n";
}