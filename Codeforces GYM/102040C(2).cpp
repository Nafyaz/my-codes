#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<LL, LL>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 10000007
#define MAXN 1000006

LL sz;
bool flag[MAXN];
vector<LL> primes;

void sieve()
{
    LL i, j;

    flag[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < MAXN; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < MAXN; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < MAXN; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

void solve(int n)
{
    LL i, temp, ans, cnt;
    vector<LL> a;

    for(i = 0; i < primes.size() && primes[i] <= n; i++)
    {
        temp = n;
        cnt = 0;

        while(temp)
        {
            cnt += temp/primes[i];
            temp /= primes[i];
        }

        a.push_back(cnt);
    }

    ans = 1;
    for(i = 0; i < a.size(); i++)
        ans = (ans * ((a[i]+1)*(a[i]+2)/2) % MOD) % MOD;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    sz = primes.size();

    int n;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        solve(n);
    }
}

