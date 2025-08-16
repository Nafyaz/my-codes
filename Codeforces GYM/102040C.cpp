#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 10000007
#define MAXN 1000006

ll sz;
bool flag[MAXN];
vector<ll> primes;
vector<ll> a;

void sieve()
{
    ll i, j;

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
    ll i, temp, s;
    a.clear();

    for(i = 0; i < primes.size(); i++)
    {
        temp = n;
        a.push_back(0);

        while(temp)
        {
            a.back() += temp/primes[i];
            temp /= primes[i];
        }
    }

    s = 1;
    for(i = 0; i < a.size(); i++)
        s = (s * ((a[i]+1)*(a[i]+2)/2) % MOD) % MOD;

    cout << s << "\n";
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

