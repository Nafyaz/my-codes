#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD1 1000000007
#define MOD2 1000000009
#define MAXN 10000007

LL arr[MAXN];
map<LL, LL> mp;
map<pLL, LL> freq;

bool flag[MAXN];
vector<LL> primes;

void sieve()
{
    LL i, j;

    flag[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        flag[i] = 1;

    for(i = 3; i*i < MAXN; i += 2)
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

void solve(int caseno)
{
    LL n, i, j, u, v, id, hash1, hash2, ans;
 
    mp.clear();
    freq.clear();


    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> u >> v;

        if(u > v)
            swap(u, v);

        arr[i] = u*(2*n+1) + v;
    }

    id = 0;
    for(i = 0; i < n; i++)
    {
        if(mp.find(arr[i]) == mp.end())
            mp[arr[i]] = id++;
    }

    for(i = 0; i < n; i++)
        arr[i] = mp[arr[i]];

    for(i = 0; i < n; i++)
    {
        hash1 = hash2 = 1;
        for(j = i; j < n; j++)
        {
            hash1 = (hash1 * primes[arr[j]]) % MOD1;
            hash2 = (hash2 * primes[arr[j]]) % MOD2;
            freq[{hash1, hash2}]++;
        }
    }

    ans = 0;
    for(auto [x, y] : freq)
        ans += y*(y-1)/2;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    sieve();

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}