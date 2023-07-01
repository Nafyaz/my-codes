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
#define MAXN 200005

LL base = 37, BIT[2][MAXN];

LL bigmod(LL a, LL p)
{
    LL ret = 1;

    while(p)
    {
        if(p%2)
            ret = (ret*a) % MOD;
        a = (a*a) % MOD;
        p /= 2;
    }

    return ret;
}

LL invmod(LL a)
{
    return bigmod(a, MOD-2);
}

void Update(LL isReverse, LL idx, LL val)
{
    while(idx < MAXN)
    {
        BIT[isReverse][idx] += val;
        BIT[isReverse][idx] %= MOD;

        idx += idx & (-idx);
    }
}

LL Query(LL isReverse, LL idx)
{
    LL ret = 0;
    while(idx > 0)
    {
        ret += BIT[isReverse][idx];
        ret %= MOD;

        idx -= idx & (-idx);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m;
    string s;

    cin >> n >> m;
    cin >> s;

    for(LL i = 1; i <= n; i++)
    {
        LL val;
        val = ((s[i-1] - 'a' + 1) * bigmod(base, i)) % MOD;
        Update(0, i, val);
        val = ((s[i-1] - 'a' + 1) * bigmod(base, n-i+1)) % MOD;
        Update(1, i, val);
    }

    while(m--)
    {
        LL type;
        cin >> type;
        
        if(type == 1)
        {
            LL k, val;
            char x;
            cin >> k >> x;

            // show(type);
            // show(k);
            // show(x) << "\n";

            val = ((s[k-1] - 'a' + 1) * bigmod(base, k)) % MOD;
            Update(0, k, -val + MOD);
            val = ((x - 'a' + 1) * bigmod(base, k)) % MOD;
            Update(0, k, val);

            val = ((s[k-1] - 'a' + 1) * bigmod(base, n-k+1)) % MOD;
            Update(1, k, -val + MOD);
            val = ((x - 'a' + 1) * bigmod(base, n-k+1)) % MOD;
            Update(1, k, val);

            s[k-1] = x;
        }
        else
        {
            LL a, b, val, valRev;
            cin >> a >> b;

            // show(type);
            // show(a);
            // show(b) << "\n";

            val = (Query(0, b) - Query(0, a-1) + MOD) % MOD;
            val = (val * invmod(bigmod(base, a-1))) % MOD;
            valRev = (Query(1, b) - Query(1, a-1) + MOD) % MOD;
            valRev = (valRev * invmod(bigmod(base, n-b))) % MOD;

            cout << (val == valRev? "YES\n" : "NO\n");
        }
    }
}