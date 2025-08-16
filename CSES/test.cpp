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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("in.txt", "w", stdout);

    vector<LL> primes, v;

    for(LL i = 2; i < 1000000; i++)
    {
        bool f = 1;
        for(LL j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
                f = 0;
        }

        if(f)
            primes.push_back(i);
    }

    for(LL i = 0; i < primes.size(); i++)
    {
        for(LL j = i+1; j < primes.size() && primes[i] * primes[j] <= 1000000; j++)
            v.push_back(primes[i]*primes[j]);
    }

    sort(v.begin(), v.end());

    reverse(v.begin(), v.end());
    while(v.size() > 200000)
        v.pop_back();
    reverse(v.begin(), v.end());

    cout << v.size() << "\n";
    for(auto u : v)
        cout << u << " ";

    cerr << v[v.size()-1] << "\n";
}