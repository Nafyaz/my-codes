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

LL base = 31, Hash[MAXN];

LL bigmod(LL a, LL p)
{
    LL ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret * a) % MOD;
        a = (a*a) % MOD;
        p /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n;
    string s;
    vector<LL> ans;

    cin >> s;
    n = s.size();

    for(LL i = 1; i <= n; i++)
        Hash[i] = (Hash[i-1] * base + (s[i-1] - 'a' + 1)) % MOD;
    
    for(LL len = 0; len < n; len++)
    {
        LL h1 = Hash[len];
        LL h2 = (Hash[n] - (Hash[n-len] * bigmod(base, len)%MOD) + MOD) % MOD;

        if(h1 == h2)
            ans.push_back(n - len);
    }

    reverse(ans.begin(), ans.end());

    for(auto u : ans)
        cout << u << " ";
    cout << "\n";
}